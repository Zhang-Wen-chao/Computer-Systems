#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <filesystem>
#include <curl/curl.h>

std::mutex mtx;

size_t WriteToFile(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    return fwrite(ptr, size, nmemb, stream);
}

void DownloadImage(const std::string& mainFolderName, const std::string& url, const std::string& folder, const std::string& filename) {
    CURL* curl;
    FILE* fp;

    curl = curl_easy_init();
    if (curl) {
        std::string filepath = folder + "/" + filename;
        std::filesystem::path fullFilePath = std::filesystem::path(mainFolderName) / std::filesystem::path(filepath);
        fp = fopen(fullFilePath.c_str(), "wb");
        if (fp) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteToFile);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 60L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
            CURLcode res = curl_easy_perform(curl);
            fclose(fp);

            std::lock_guard<std::mutex> lock(mtx);
            if (res == CURLE_OK) {
                std::cout << "Downloaded: " << url << std::endl;
            } else {
                std::cerr << "Failed to download: " << url << " (" << curl_easy_strerror(res) << ")" << std::endl;
            }
        }
        curl_easy_cleanup(curl);
    }
}

int main(int argc, char* argv[]) {
    const std::string MAIN_FOLDER_NAME(argv[1]);
    std::filesystem::create_directory(MAIN_FOLDER_NAME);
    std::ifstream file(MAIN_FOLDER_NAME + "_urls.txt");
    std::string line;
    std::vector<std::tuple<std::string, std::string, std::string, std::string>> imageInfos;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        size_t pos1 = line.find("::");
        size_t pos2 = line.find("::", pos1 + 2);
        size_t pos3 = line.find("::", pos2 + 2);
        if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos) {
            std::string parentFolder = line.substr(0, pos1);
            std::string subFolder = line.substr(pos1 + 2, pos2 - pos1 - 2);
            std::string filename = line.substr(pos2 + 2, pos3 - pos2 - 2);
            std::string url = line.substr(pos3 + 2);
            imageInfos.push_back(std::make_tuple(parentFolder, subFolder, filename, url));
        }
    }

    for (const auto& imageInfo : imageInfos) {
        std::string folder = (std::filesystem::path(MAIN_FOLDER_NAME) /
                      std::filesystem::path(std::get<0>(imageInfo)) /
                      std::filesystem::path(std::get<1>(imageInfo))).string();
        std::filesystem::create_directories(folder);
    }

    std::vector<std::thread> threads;
    for (const auto& imageInfo : imageInfos) {
        threads.emplace_back(DownloadImage, MAIN_FOLDER_NAME, std::get<3>(imageInfo), std::get<0>(imageInfo) + "/" + std::get<1>(imageInfo), std::get<2>(imageInfo));
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return 0;
}
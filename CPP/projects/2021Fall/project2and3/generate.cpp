#include <iostream>
#include <fstream>
#include <random>
#include <string>

using namespace std;

// Function to generate a random matrix of given size
void generateMatrixFile(const string& filename, int rows, int cols) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(0.0, 1.0);

    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file << dis(gen) << " ";
        }
        file << endl;
    }

    file.close();
}

int main() {
    const string filenames[] = {
        "mat-A-32.txt", "mat-B-32.txt",
        "mat-A-256.txt", "mat-B-256.txt",
        "mat-A-2048.txt", "mat-B-2048.txt"
    };

    const int sizes[] = {32, 256, 2048};

    for (int i = 0; i < 6; ++i) {
        string filename = filenames[i];
        int size = sizes[i / 2];

        generateMatrixFile(filename, size, size);

        cout << "Generated " << filename << endl;
    }

    return 0;
}

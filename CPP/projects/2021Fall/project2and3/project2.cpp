/*
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2$ g++ project2.cpp -o matmul
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2$ ./matmul mat-A-32.txt mat-B-32.txt out32.txt
Float matrix multiplication completed. Duration: 0 milliseconds.
Double matrix multiplication completed. Duration: 0 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2$ ./matmul mat-A-256.txt mat-B-256.txt out256.txt
Float matrix multiplication completed. Duration: 425 milliseconds.
Double matrix multiplication completed. Duration: 384 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2$ ./matmul mat-A-2048.txt mat-B-2048.txt out2048.txt
Float matrix multiplication completed. Duration: 292137 milliseconds.
Double matrix multiplication completed. Duration: 353739 milliseconds.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to multiply two matrices
template <typename T>
vector<vector<T>> matrixMultiply(const vector<vector<T>>& matrixA, const vector<vector<T>>& matrixB) {
    int rowsA = matrixA.size();
    int colsA = matrixA[0].size();
    int colsB = matrixB[0].size();

    vector<vector<T>> result(rowsA, vector<T>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    return result;
}

// Function to read a matrix from a file
template <typename T>
vector<vector<T>> readMatrixFromFile(const string& filename, int rows, int cols) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    vector<vector<T>> matrix(rows, vector<T>(cols));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> matrix[i][j])) {
                cerr << "Error reading file: " << filename << endl;
                exit(1);
            }
        }
    }

    file.close();
    return matrix;
}

// Function to write a matrix to a file
template <typename T>
void writeMatrixToFile(const vector<vector<T>>& matrix, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            file << matrix[i][j] << " ";
        }
        file << endl;
    }

    file.close();
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: ./matmul matrixA_file matrixB_file output_file" << endl;
        return 1;
    }

    string matrixAFile = argv[1];
    string matrixBFile = argv[2];
    string outputFile = argv[3];

    // Read matrices from files
    vector<vector<float>> matrixA;
    vector<vector<float>> matrixB;
    vector<vector<double>> matrixADouble;
    vector<vector<double>> matrixBDouble;

    if (matrixAFile == "mat-A-32.txt") {
        matrixA = readMatrixFromFile<float>(matrixAFile, 32, 32);
        matrixB = readMatrixFromFile<float>(matrixBFile, 32, 32);
    } else if (matrixAFile == "mat-A-256.txt") {
        matrixA = readMatrixFromFile<float>(matrixAFile, 256, 256);
        matrixB = readMatrixFromFile<float>(matrixBFile, 256, 256);
    } else if (matrixAFile == "mat-A-2048.txt") {
        matrixA = readMatrixFromFile<float>(matrixAFile, 2048, 2048);
        matrixB = readMatrixFromFile<float>(matrixBFile, 2048, 2048);
    } else {
        cerr << "Invalid matrix file name: " << matrixAFile << endl;
        return 1;
    }

    // Multiply matrices (float)
    auto startFloat = high_resolution_clock::now();
    vector<vector<float>> resultFloat = matrixMultiply(matrixA, matrixB);
    auto endFloat = high_resolution_clock::now();
    auto durationFloat = duration_cast<milliseconds>(endFloat - startFloat);

    // Write float result to file
    writeMatrixToFile<float>(resultFloat, outputFile + "f.txt");
    cout << "Float matrix multiplication completed. Duration: " << durationFloat.count() << " milliseconds." << endl;

    // Read matrices from files
    matrixADouble = readMatrixFromFile<double>(matrixAFile, matrixA.size(), matrixA[0].size());
    matrixBDouble = readMatrixFromFile<double>(matrixBFile, matrixB.size(), matrixB[0].size());

    // Multiply matrices (double)
    auto startDouble = high_resolution_clock::now();
    vector<vector<double>> resultDouble = matrixMultiply(matrixADouble, matrixBDouble);
    auto endDouble = high_resolution_clock::now();
    auto durationDouble = duration_cast<milliseconds>(endDouble - startDouble);

    // Write double result to file
    writeMatrixToFile<double>(resultDouble, outputFile + "d.txt");
    cout << "Double matrix multiplication completed. Duration: " << durationDouble.count() << " milliseconds." << endl;

    return 0;
}

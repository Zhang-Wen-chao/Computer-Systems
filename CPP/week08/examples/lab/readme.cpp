/*
Create two 1Mx1K float matrices matA and matB, compute matA + matB.

* compute the result row by row and col by col, compare the performance difference
g++ readme.cpp
Row by row computation time: 38196 ms
Column by column computation time: 244108 ms

* use -O3 to improve the speed
g++ -O3 readme.cpp
Row by row computation time: 1461 ms
Column by column computation time: 70473 ms

* improve the speed using SIMD, will the speed be improved? Why?
g++ readme.cpp
computeSumSIMD time: 26396 ms
g++ -O3 readme.cpp
computeSumSIMD time: 1779 ms
*/

#include <iostream>
#include <vector>
#include <chrono>
#include <immintrin.h>

const int NUM_ROWS = 1000000;
const int NUM_COLS = 1000;

void computeRowByRow(const std::vector<std::vector<float>>& matA, const std::vector<std::vector<float>>& matB, std::vector<std::vector<float>>& result) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void computeColByCol(const std::vector<std::vector<float>>& matA, const std::vector<std::vector<float>>& matB, std::vector<std::vector<float>>& result) {
    for (int j = 0; j < NUM_COLS; j++) {
        for (int i = 0; i < NUM_ROWS; i++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void computeSumSIMD(const std::vector<std::vector<float>>& matA, const std::vector<std::vector<float>>& matB, std::vector<std::vector<float>>& result) {
    for (int i = 0; i < NUM_ROWS; i++) {
        __m128* vecA = (__m128*)matA[i].data();
        __m128* vecB = (__m128*)matB[i].data();
        __m128* vecResult = (__m128*)result[i].data();
        
        for (int j = 0; j < NUM_COLS / 4; j++) {
            vecResult[j] = _mm_add_ps(vecA[j], vecB[j]);
        }
    }
}


int main() {
    std::vector<std::vector<float>> matA(NUM_ROWS, std::vector<float>(NUM_COLS, 1.0f));
    std::vector<std::vector<float>> matB(NUM_ROWS, std::vector<float>(NUM_COLS, 2.0f));
    std::vector<std::vector<float>> result(NUM_ROWS, std::vector<float>(NUM_COLS));

    // // Compute row by row
    // auto startRow = std::chrono::high_resolution_clock::now();
    // computeRowByRow(matA, matB, result);
    // auto endRow = std::chrono::high_resolution_clock::now();

    // // Compute col by col
    // auto startCol = std::chrono::high_resolution_clock::now();
    // computeColByCol(matA, matB, result);
    // auto endCol = std::chrono::high_resolution_clock::now();

    // Compute SIMD
    auto startSIMD = std::chrono::high_resolution_clock::now();
    computeSumSIMD(matA, matB, result);
    auto endSIMD = std::chrono::high_resolution_clock::now();

    // Calculate execution time in milliseconds
    // auto durationRow = std::chrono::duration_cast<std::chrono::milliseconds>(endRow - startRow);
    // auto durationCol = std::chrono::duration_cast<std::chrono::milliseconds>(endCol - startCol);
    auto durationCol = std::chrono::duration_cast<std::chrono::milliseconds>(endSIMD - startSIMD);





    // std::cout << "Row by row computation time: " << durationRow.count() << " ms" << std::endl;
    // std::cout << "Column by column computation time: " << durationCol.count() << " ms" << std::endl;
    std::cout << "computeSumSIMD time: " << durationCol.count() << " ms" << std::endl;


    return 0;
}

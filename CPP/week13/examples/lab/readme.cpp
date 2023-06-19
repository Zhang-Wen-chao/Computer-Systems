/*
Create a matrix template class which can handle different data types.

*/

#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t numRows, size_t numCols)
        : rows(numRows), cols(numCols), data(numRows, std::vector<T>(numCols)) {}

    size_t numRows() const {
        return rows;
    }

    size_t numCols() const {
        return cols;
    }

    T& operator()(size_t rowIndex, size_t colIndex) {
        if (rowIndex >= rows || colIndex >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[rowIndex][colIndex];
    }

    const T& operator()(size_t rowIndex, size_t colIndex) const {
        if (rowIndex >= rows || colIndex >= cols) {
            throw std::out_of_range("Index out of range");
        }
        return data[rowIndex][colIndex];
    }
};

int main() {
    Matrix<int> intMatrix(3, 4);
    intMatrix(0, 0) = 1;
    intMatrix(0, 1) = 2;
    intMatrix(1, 2) = 3;

    Matrix<double> doubleMatrix(2, 2);
    doubleMatrix(0, 0) = 1.5;
    doubleMatrix(1, 1) = 2.7;

    Matrix<char> charMatrix(1, 3);
    charMatrix(0, 0) = 'A';
    charMatrix(0, 1) = 'B';
    charMatrix(0, 2) = 'C';

    // Printing the matrices for verification
    std::cout << "Int Matrix:\n";
    for (size_t i = 0; i < intMatrix.numRows(); ++i) {
        for (size_t j = 0; j < intMatrix.numCols(); ++j) {
            std::cout << intMatrix(i, j) << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "Double Matrix:\n";
    for (size_t i = 0; i < doubleMatrix.numRows(); ++i) {
        for (size_t j = 0; j < doubleMatrix.numCols(); ++j) {
            std::cout << doubleMatrix(i, j) << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "Char Matrix:\n";
    for (size_t i = 0; i < charMatrix.numRows(); ++i) {
        for (size_t j = 0; j < charMatrix.numCols(); ++j) {
            std::cout << charMatrix(i, j) << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}

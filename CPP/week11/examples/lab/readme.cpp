/*
Create a class for matrices which elements are in float. The class should support the follow operations and has no memory management problem. When a matrix is assigned to another by =, the two matrices will share the same data.
`class Matrix{...};`
`Matrix a(3,4);`
`Matrix b(3,4);`
`Matrix c = a + b;`
`Matrix d = a * 2.0f;`
*/
#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<float> data;

public:
    Matrix(int numRows, int numCols) : rows(numRows), cols(numCols), data(numRows * numCols) {}

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}

    // Overloaded assignment operator (=)
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            cols = other.cols;
            data = other.data;
        }
        return *this;
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    // Overloaded addition operator (+)
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrix dimensions must be the same for addition." << std::endl;
            return Matrix(0, 0); // Return an empty matrix if dimensions mismatch
        }

        Matrix result(rows, cols);
        for (int i = 0; i < data.size(); i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Overloaded multiplication operator (*) with scalar value
    Matrix operator*(float scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < data.size(); i++) {
            result.data[i] = data[i] * scalar;
        }
        return result;
    }

    void setData(int row, int col, float value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            data[row * cols + col] = value;
        }
    }

    // Friend function for the overloaded stream insertion operator (<<)
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.rows; i++) {
            for (int j = 0; j < matrix.cols; j++) {
                os << matrix.data[i * matrix.cols + j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
};

int main() {
    Matrix a(3, 4);
    Matrix b(3, 4);

    // Initialize matrices a and b
    for (int i = 0; i < a.getRows(); i++) {
        for (int j = 0; j < a.getCols(); j++) {
            a.setData(i, j, i + j); // Sample initialization
            b.setData(i, j, i - j); // Sample initialization
        }
    }

    Matrix c = a + b;
    Matrix d = a * 2.0f;

    std::cout << "Matrix a:" << std::endl;
    std::cout << a << std::endl;

    std::cout << "Matrix b:" << std::endl;
    std::cout << b << std::endl;

    std::cout << "Matrix c = a + b:" << std::endl;
    std::cout << c << std::endl;

    std::cout << "Matrix d = a * 2.0f:" << std::endl;
    std::cout << d << std::endl;

    return 0;
}

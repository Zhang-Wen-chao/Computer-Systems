/*
Create a class Matrix to describe a matrix. The element type is float. One member of the class is shared_ptr<float> for the matrix data. 
The two matrices can share the same data through a copy constructor or a copy assignment.
The following code can run smoothly without memory problems.

class Matrix{...};
Matrix a(3,4);
Matrix b(3,4);
Matrix c = a + b;
Matrix d = a;
d = b;
*/

#include <iostream>
#include <memory>
#include <stdexcept>

class Matrix {
private:
    int rows;
    int columns;
    std::shared_ptr<float[]> data;

public:
    // Default constructor
    Matrix() : rows(0), columns(0), data(nullptr) {}

    // Parameterized constructor
    Matrix(int rows, int columns) : rows(rows), columns(columns), data(new float[rows * columns]) {}

    // Copy constructor
    Matrix(const Matrix& other) : rows(other.rows), columns(other.columns), data(other.data) {}

    // Copy assignment operator
    Matrix& operator=(const Matrix& other) {
        if (this != &other) {
            rows = other.rows;
            columns = other.columns;
            data = other.data;
        }
        return *this;
    }

    // Addition operator
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns)
            throw std::invalid_argument("Matrix dimensions do not match.");

        Matrix result(rows, columns);
        for (int i = 0; i < rows * columns; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Set value at specific position
    void setValue(int row, int column, float value) {
        data[row * columns + column] = value;
    }

    // Print matrix
    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << data[i * columns + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

int main() {
    Matrix a(3, 4);
    Matrix b(3, 4);
    
    // Assign some values to matrices a and b
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            a.setValue(i, j, static_cast<float>((i + 1) * (j + 1)));
            b.setValue(i, j, static_cast<float>((i + 1) * (j + 2)));
        }
    }
    
    Matrix c = a + b;
    Matrix d = a;
    
    std::cout << "Matrix a:" << std::endl;
    a.print();
    
    std::cout << "Matrix b:" << std::endl;
    b.print();
    
    std::cout << "Matrix c = a + b:" << std::endl;
    c.print();
    
    std::cout << "Matrix d = a:" << std::endl;
    d.print();
    
    d = b;
    std::cout << "After d = b, Matrix d:" << std::endl;
    d.print();
    
    return 0;
}

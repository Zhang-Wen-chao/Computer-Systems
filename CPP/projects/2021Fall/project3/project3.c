#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int rows;
    int cols;
    float** data;
} Matrix;

// Function to create a matrix
Matrix createMatrix(int rows, int cols) {
    Matrix matrix;
    matrix.rows = rows;
    matrix.cols = cols;
    
    // Allocate memory for the matrix data
    matrix.data = (float**)malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; ++i) {
        matrix.data[i] = (float*)malloc(cols * sizeof(float));
    }
    
    return matrix;
}

// Function to delete a matrix and free the allocated memory
void deleteMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; ++i) {
        free(matrix->data[i]);
    }
    free(matrix->data);
}

// Function to copy a matrix
Matrix copyMatrix(const Matrix* source) {
    int rows = source->rows;
    int cols = source->cols;
    
    Matrix dest = createMatrix(rows, cols);
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dest.data[i][j] = source->data[i][j];
        }
    }
    
    return dest;
}

// Function to multiply two matrices
Matrix multiplyMatrices(const Matrix* matrixA, const Matrix* matrixB) {
    int rowsA = matrixA->rows;
    int colsA = matrixA->cols;
    int colsB = matrixB->cols;

    Matrix result = createMatrix(rowsA, colsB);

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result.data[i][j] += matrixA->data[i][k] * matrixB->data[k][j];
            }
        }
    }

    return result;
}

// Function to read a matrix from a file
Matrix readMatrixFromFile(const char* filename, int rows, int cols) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    Matrix matrix = createMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (fscanf(file, "%f", &matrix.data[i][j]) != 1) {
                fprintf(stderr, "Error reading file: %s\n", filename);
                exit(1);
            }
        }
    }

    fclose(file);
    return matrix;
}

// Function to write a matrix to a file
void writeMatrixToFile(const Matrix* matrix, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }

    int rows = matrix->rows;
    int cols = matrix->cols;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            fprintf(file, "%.6f ", matrix->data[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, “Usage: ./matmul matrixA_file matrixB_file output_file\n”);
        return 1;
    }

    const char* matrixAFile = argv[1];
    const char* matrixBFile = argv[2];
    const char* outputFile = argv[3];

    // Read matrices from files
    Matrix matrixA = readMatrixFromFile(matrixAFile, 32, 32);
    Matrix matrixB = readMatrixFromFile(matrixBFile, 32, 32);

    // Multiply matrices
    Matrix result = multiplyMatrices(&matrixA, &matrixB);

    // Write result to file
    writeMatrixToFile(&result, outputFile);

    // Clean up
    deleteMatrix(&matrixA);
    deleteMatrix(&matrixB);
    deleteMatrix(&result);

    return 0;

}

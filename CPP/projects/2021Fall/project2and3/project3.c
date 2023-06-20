/*
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ gcc project3.c -o matmul
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-32.txt mat-B-32.txt out32.txt
Matrix multiplication completed. Duration: 0.284 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-256.txt mat-B-256.txt out256.txt
Matrix multiplication completed. Duration: 163.922 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-2048.txt mat-B-2048.txt out2048.txt
Matrix multiplication completed. Duration: 141772.735 milliseconds.


(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ gcc project3.c -o matmul -lopenblas
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-32.txt mat-B-32.txt out32.txt
Matrix multiplication completed. Duration: 0.280 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-256.txt mat-B-256.txt out256.txt
Matrix multiplication completed. Duration: 126.317 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-2048.txt mat-B-2048.txt out2048.txt
Matrix multiplication completed. Duration: 145404.723 milliseconds.

(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ gcc project3.c -o matmul -O3 -lopenblas
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-32.txt mat-B-32.txt out32.txt
Matrix multiplication completed. Duration: 0.044 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-256.txt mat-B-256.txt out256.txt
Matrix multiplication completed. Duration: 19.624 milliseconds.
(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/projects/2021Fall/project2and3$ ./matmul mat-A-2048.txt mat-B-2048.txt out2048.txt
Matrix multiplication completed. Duration: 85935.856 milliseconds.



加上编译器优化标志"-O3"可以启用GCC的最高级别优化，这将使编译器进行更多的优化，以提高生成的机器代码的性能。优化标志可以使编译器更好地理解代码，并使用更高效的算法和技术来生成优化的代码。这可能包括循环展开、向量化、内联函数等。

当您使用"-lopenblas"链接OpenBLAS库时，编译器将使用OpenBLAS提供的优化代码，但编译器自身的优化标志也可以对代码进行优化。因此，结合使用"-O3"和"-lopenblas"可以最大程度地发挥编译器和OpenBLAS的优化能力，从而获得更好的性能。

在您的示例中，当您只使用"-lopenblas"时，没有明显的提速，这可能是因为编译器默认的优化级别不够高。而当您加上"-O3"优化标志时，编译器进行了更多的优化，从而导致了明显的性能提升。

需要注意的是，优化标志的效果可能因编译器版本、代码特性和目标平台而异。因此，对于不同的情况，可能需要进行一些实验和调整，以找到最佳的优化配置。

总结起来，结合使用"-O3"优化标志和"-lopenblas"可以最大程度地发挥编译器和OpenBLAS的优化能力，从而获得更好的性能。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

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
        fprintf(stderr, "Usage: ./matmul matrixA_file matrixB_file output_file\n");
        return 1;
    }

    const char* matrixAFile = argv[1];
    const char* matrixBFile = argv[2];
    const char* outputFile = argv[3];

    int matrixARows, matrixACols, matrixBRows, matrixBCols;
    Matrix matrixA, matrixB;

    if (strcmp(matrixAFile, "mat-A-32.txt") == 0) {
        matrixARows = 32;
        matrixACols = 32;
    } else if (strcmp(matrixAFile, "mat-A-256.txt") == 0) {
        matrixARows = 256;
        matrixACols = 256;
    } else if (strcmp(matrixAFile, "mat-A-2048.txt") == 0) {
        matrixARows = 2048;
        matrixACols = 2048;
    } else {
        fprintf(stderr, "Invalid matrix file name: %s\n", matrixAFile);
        return 1;
    }

    matrixA = readMatrixFromFile(matrixAFile, matrixARows, matrixACols);
    matrixB = readMatrixFromFile(matrixBFile, matrixACols, matrixACols);

    struct timeval start, end;
    gettimeofday(&start, NULL);

    Matrix result = multiplyMatrices(&matrixA, &matrixB);

    gettimeofday(&end, NULL);
    double duration = ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);

    writeMatrixToFile(&result, outputFile);
    printf("Matrix multiplication completed. Duration: %.3f milliseconds.\n", duration);

    deleteMatrix(&matrixA);
    deleteMatrix(&matrixB);
    deleteMatrix(&result);

    return 0;
}

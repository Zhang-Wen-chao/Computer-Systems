/*
Write a program to add 2 float vectors whose size should be more than 1M. You can initialize the two vectors with values like 0.f, 1.f, 2.f, …
Use pure C source code and SIMD (AVX2 or NEON) separately, and compare their speeds
Use OpenMP to speed up the addition. Can you get the correct result?


Pure C: Time taken = 0.050396 seconds
OpenMP: Time taken = 0.034864 seconds
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef __AVX2__
#include <immintrin.h>
#elif defined(__ARM_NEON)
#include <arm_neon.h>
#endif

#define VECTOR_SIZE 10000000

void addVectorsC(const float* vecA, const float* vecB, float* result, int size) {
    for (int i = 0; i < size; i++) {
        result[i] = vecA[i] + vecB[i];
    }
}

#ifdef __AVX2__
void addVectorsSIMDAVX2(const float* vecA, const float* vecB, float* result, int size) {
    int numSIMD = size / 8;
    __m256* simdVecA = (__m256*)vecA;
    __m256* simdVecB = (__m256*)vecB;
    __m256* simdResult = (__m256*)result;

    for (int i = 0; i < numSIMD; i++) {
        simdResult[i] = _mm256_add_ps(simdVecA[i], simdVecB[i]);
    }
}
#endif

#ifdef __ARM_NEON
void addVectorsSIMDNEON(const float* vecA, const float* vecB, float* result, int size) {
    int numSIMD = size / 4;
    float32x4_t simdVecA, simdVecB, simdResult;

    for (int i = 0; i < numSIMD; i++) {
        simdVecA = vld1q_f32(&vecA[i * 4]);
        simdVecB = vld1q_f32(&vecB[i * 4]);
        simdResult = vaddq_f32(simdVecA, simdVecB);
        vst1q_f32(&result[i * 4], simdResult);
    }
}
#endif

void printVector(const float* vector, int size) {
    for (int i = 0; i < size; i++) {
        printf("%f ", vector[i]);
    }
    printf("\n");
}

int main() {
    float* vecA = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float* vecB = (float*)malloc(VECTOR_SIZE * sizeof(float));
    float* result = (float*)malloc(VECTOR_SIZE * sizeof(float));

    // Initialize vectors with values like 0.f, 1.f, 2.f, ...
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vecA[i] = (float)i;
        vecB[i] = (float)i;
    }

    clock_t start, end;
    double cpu_time_used;

    // Pure C implementation
    start = clock();
    addVectorsC(vecA, vecB, result, VECTOR_SIZE);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Pure C: Time taken = %f seconds\n", cpu_time_used);

#ifdef __AVX2__
    // SIMD (AVX2) implementation
    start = clock();
    addVectorsSIMDAVX2(vecA, vecB, result, VECTOR_SIZE);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("SIMD (AVX2): Time taken = %f seconds\n", cpu_time_used);
#endif

#ifdef __ARM_NEON
    // SIMD (NEON) implementation
    start = clock();
    addVectorsSIMDNEON(vecA, vecB, result, VECTOR_SIZE);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("SIMD (NEON): Time taken = %f seconds\n", cpu_time_used);
#endif

    // OpenMP implementation
    start = clock();
    #pragma omp parallel for
    for (int i = 0; i < VECTOR_SIZE; i++) {
        result[i] = vecA[i] + vecB[i];
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("OpenMP: Time taken = %f seconds\n", cpu_time_used);

    // Verify correctness by comparing results
    float* resultC = (float*)malloc(VECTOR_SIZE * sizeof(float));
    addVectorsC(vecA, vecB, resultC, VECTOR_SIZE);
    for (int i = 0; i < VECTOR_SIZE; i++) {
        if (result[i] != resultC[i]) {
            printf("Error: Result mismatch at index %d\n", i);
            break;
        }
    }
    free(resultC);

    free(vecA);
    free(vecB);
    free(result);

    return 0;
}

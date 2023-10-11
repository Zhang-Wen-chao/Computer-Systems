#include <stdio.h>

__global__ void kernel() {
    printf("Hello from GPU\n");
}

int main() {
    printf("Hello from CPU\n");
    
    kernel<<<1,1>>>();
    
    cudaDeviceReset(); // if no this line, it can not output hello world from gpu
    
    return 0;
}

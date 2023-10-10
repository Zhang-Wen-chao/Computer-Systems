// Write an efficient program to count the number of 1s in the binary representation of an integer.
#include <stdio.h>

/* Function to get no of set bits in binary
   representation of positive integer n */
unsigned int countSetBits(unsigned int n)
{
    unsigned int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

/* Program to test function countSetBits */
int main()
{
    int i = 5;
    printf("The number of set bits in %d is: %d\n", i, countSetBits(i));
    return 0;
}

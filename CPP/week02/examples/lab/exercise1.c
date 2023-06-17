/*
Compile and run the following program, what is the result? 
You need to explain the reason to a SA to pass the test.

*/

#include <stdio.h>

int main()
{
    signed char a = 127;
    unsigned char b = 0xff;
    unsigned char c = 0;

    a++;
    b++;
    c--;
    printf("a=%d\nb=%d\nc=%d\n",a,b,c);

    return 0;
}
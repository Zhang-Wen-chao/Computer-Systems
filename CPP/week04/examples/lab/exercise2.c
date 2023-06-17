/*
Run the program and explain the result to SA. You can write a program to check whether you system is little-endian or big-endian.
*/


// #include <stdio.h>

// union data{
//     int n;
//     char ch;
//     short m;
// };

// int main()
// {
//     union data a;
//     printf("%d, %d\n", sizeof(a), sizeof(union data) );
//     a.n = 0x40;
//     printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//     a.ch = '9';
//     printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//     a.m = 0x2059;
//     printf("%X, %c, %hX\n", a.n, a.ch, a.m);
//     a.n = 0x3E25AD54;
//     printf("%X, %c, %hX\n", a.n, a.ch, a.m);

//     return 0;
// }

// 4, 4
// 40, @, 40
// 39, 9, 39
// 2059, Y, 2059
// 3E25AD54, T, AD54

#include <stdio.h>

int main() {
    union {
        unsigned int value;
        unsigned char byte[sizeof(unsigned int)];
    } data;

    data.value = 0x01;

    if (data.byte[0] == 0x01) {
        printf("Your system is little-endian.\n");
    } else {
        printf("Your system is big-endian.\n");
    }

    return 0;
}

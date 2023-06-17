/*
Can the program be run correctly?
How to fix the bugs?

在给定的代码中，`sum`函数尝试修改传递给它的数组元素，但是在函数参数中将数组指针声明为`const int*`，这意味着它们是只读的，不允许在函数内部修改。因此，如果要在`sum`函数中修改数组元素，需要将函数参数中的`const`关键字移除。

在修改后的代码中，`sum`函数的参数中的第一个数组指针变为`int*`，允许在函数内部修改数组元素的值。而第二个数组指针仍然保持为`const int*`，确保不对其进行修改。这样，`sum`函数就能正确地将`b`数组的元素加到`a`数组对应位置的元素上。
*/

// #include <iostream>
// #define SIZE 5
// void sum(const int *, const int *, int);
// int main() 
// {
//     int a[SIZE] = {10,20,30,40,50};
//     int b[SIZE] = {1,2,3,4,5};
//     std::cout << "Before calling the function, the contents of a are:" << std::endl;
//     for(int i = 0; i < SIZE; i++)
//         std::cout << a[i] << " ";
//     // passing arrays to function
//     sum(a,b,SIZE);

//     std::cout << "\nAfter calling the function, the contents of a are:" << std::endl;
//     for(int i = 0; i < SIZE; i++)
//     std::cout << a[i] << " ";
//     std::cout << std::endl;
//     return 0;
// }
// void sum(const int *pa, const int *pb, int n)
// {
//     for(int i = 0; i < n; i++)
//     {
//         *pa += *pb;
//         pa++;
//         pb++;
//     }
// }


#include <iostream>
#define SIZE 5

void sum(int *, const int *, int);

int main() 
{
    int a[SIZE] = {10, 20, 30, 40, 50};
    int b[SIZE] = {1, 2, 3, 4, 5};

    std::cout << "Before calling the function, the contents of a are:" << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << a[i] << " ";

    // passing arrays to function
    sum(a, b, SIZE);

    std::cout << "\nAfter calling the function, the contents of a are:" << std::endl;
    for (int i = 0; i < SIZE; i++)
        std::cout << a[i] << " ";

    std::cout << std::endl;
    return 0;
}

void sum(int *pa, const int *pb, int n)
{
    for (int i = 0; i < n; i++)
    {
        *pa += *pb;
        pa++;
        pb++;
    }
}

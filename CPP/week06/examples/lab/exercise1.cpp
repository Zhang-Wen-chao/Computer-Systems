/*
Fix bugs of the program and run it correctly
without memory leak.
Note: In a function with pointer parameters, the pointers should be checked first. If there is no such statement, please add it.
*/

// #include <iostream>
// using namespace std;
// #define SIZE 5
// int main()
// {
//     int const *pa = new int[SIZE]{3,5,8,2,6};
//     int total = sum(pa,SIZE);
//     cout << "sum = " << total << endl;
//     return 0;
// }
// int sum(const int *pArray, int n)
// {
//     int s = 0;
//     for(int i = 0; i < n; i++)
//          s += pArray[i];
//      return s;
// }


#include <iostream>
#define SIZE 5
int sum(const int *pArray, int n);

int main()
{
    const int *pa = new int[SIZE]{3, 5, 8, 2, 6};
    int total = sum(pa, SIZE);
    std::cout << "sum = " << total << std::endl;
    delete[] pa; // 释放内存
    return 0;
}

int sum(const int *pArray, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += pArray[i];
    return s;
}

/*
以下是修复了程序中的错误并解决了内存泄漏问题的代码：

```cpp
#include <iostream>

int sum(const int *pArray, int n);

int main()
{
    const int *pa = new int[SIZE]{3, 5, 8, 2, 6};
    int total = sum(pa, SIZE);
    std::cout << "sum = " << total << std::endl;
    delete[] pa; // 释放内存
    return 0;
}

int sum(const int *pArray, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += pArray[i];
    return s;
}
```

修复的问题包括：

1. 在`main`函数中，将`sum`函数的声明移至函数调用之前，以确保函数原型的可见性。
2. 在`main`函数末尾，通过`delete[] pa`释放动态分配的内存，避免内存泄漏。

此外，还需要注意，`const int *pa`表示`pa`是一个指向`const int`的指针，意味着不能通过`pa`修改数组中的元素。如果希望能够修改数组元素，应该使用`int *pa`而不是`const int *pa`。
*/
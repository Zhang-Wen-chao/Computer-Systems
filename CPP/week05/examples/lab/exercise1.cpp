/*
Run the program and explain the result to SA. 

这段代码涉及了指针和变量的内存大小、地址以及它们之间的关系。下面是对结果的解释：

sizeof(cc) = 1, sizeof(pc) = 8: cc是一个char类型的变量，占用1个字节的内存。pc是一个指向char类型的指针，无论指针指向的类型大小如何，指针本身占用8个字节的内存（在大多数64位系统上）。

sizeof(ii) = 4, sizeof(pi) = 8: ii是一个int类型的变量，占用4个字节的内存。pi是一个指向int类型的指针，指针本身占用8个字节的内存。

sizeof(ff) = 4, sizeof(pf) = 8: ff是一个float类型的变量，占用4个字节的内存。pf是一个指向float类型的指针，指针本身占用8个字节的内存。

sizeof(dd) = 8, sizeof(pd) = 8: dd是一个double类型的变量，占用8个字节的内存。pd是一个指向double类型的指针，指针本身占用8个字节的内存。

&pc = 0x7ffe2ab04568, pc = 0x7ffe2ab04567, *pc = A: &pc表示指针pc本身的地址，pc的值表示它所指向的地址，*pc表示指针pc指向的值。在这个例子中，pc指向字符变量cc的地址，所以*pc的值为A。

&pi = 0x7ffe2ab04558, pi = 0x7ffe2ab04554, *pi = 10: &pi表示指针pi本身的地址，pi的值表示它所指向的地址，*pi表示指针pi指向的值。在这个例子中，pi指向整数变量ii的地址，所以*pi的值为10。

&pf = 0x7ffe2ab04548, pf = 0x7ffe2ab04544, *pf = 23.4: &pf表示指针pf本身的地址，pf的值表示它所指向的地址，*pf表示指针pf指向的值。在这个例子中，pf指向浮点数变量ff的地址，所以*pf的值为23.4。

&pd = 0x7ffe2ab04538, pd = 0x7ffe2ab04530, *pd = 123.78: &pd表示指针pd本身的地址，pd的值表示它所指向的
*/

#include <iostream>
using namespace std;

int main()
{
    char *pc, cc = 'A';
    int *pi, ii = 10;
    float *pf, ff = 23.4f;
    double *pd, dd = 123.78;

    pc = &cc;
    pi = &ii;
    pf = &ff;
    pd = &dd;

    cout << "sizeof(cc) = " << sizeof(cc) << ", sizeof(pc) = " << sizeof(pc)  << endl;
    cout << "sizeof(ii) = " << sizeof(ii) << ", sizeof(pi) = " << sizeof(pi) <<  endl;
    cout << "sizeof(ff) = " << sizeof(ff) << ", sizeof(pf) = " << sizeof(pf) <<  endl;
    cout << "sizeof(dd) = " << sizeof(dd) << ", sizeof(pd) = " << sizeof(pd) <<  endl;

    cout << "&pc = " << &pc << ", pc = " << static_cast <void*>(pc) << ", *pc = " << *pc << endl;
    cout << "&pi = " << &pi << ", pi = " << pi << ", *pi = " << *pi << endl;
    cout << "&pf = " << &pf << ", pf = " << pf << ", *pf = " << *pf << endl;
    cout << "&pd = " << &pd << ", pd = " << pd << ", *pd = " << *pd << endl;

    const char *msg = "C/C++ programming is fun.";
    const char *copy;

    copy = msg;

    cout << "msg = " << msg << ",its address is: " << (void*)msg << ", &msg = " << &msg << endl;
    cout << "copy= " << copy << ",its address is: " << (void*)copy << ", &copy= " << &copy << endl;

    return 0;
}

// sizeof(cc) = 1, sizeof(pc) = 8
// sizeof(ii) = 4, sizeof(pi) = 8
// sizeof(ff) = 4, sizeof(pf) = 8
// sizeof(dd) = 8, sizeof(pd) = 8
// &pc = 0x7ffe2ab04568, pc = 0x7ffe2ab04567, *pc = A
// &pi = 0x7ffe2ab04558, pi = 0x7ffe2ab04554, *pi = 10
// &pf = 0x7ffe2ab04548, pf = 0x7ffe2ab04544, *pf = 23.4
// &pd = 0x7ffe2ab04538, pd = 0x7ffe2ab04530, *pd = 123.78
// msg = C/C++ programming is fun.,its address is: 0x558e153750e1, &msg = 0x7ffe2ab04528
// copy= C/C++ programming is fun.,its address is: 0x558e153750e1, &copy= 0x7ffe2ab04520
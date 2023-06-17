/*
Run the program and explain the result to SA. 

这段代码涉及指针和类型转换，下面是对结果的解释：

*p++ = 15, *p = 17: a是一个二维整数数组。p是一个指向数组a第二行的第一个元素的指针。p += 3将指针p向后移动3个位置，然后通过*p++访问指针p所指向的元素并进行后缀递增。结果是*p++的值为15，并且*p的值为17。

r = (char *)q; cout << r << endl;: 这段代码首先将指针q转换为char*类型，并将结果赋值给指针r。然后，使用cout输出指针r指向的字符串。由于我们将q的类型转换为了char*，因此r指向了字符串的起始位置，从而可以打印出完整的字符串：“to programming.”。

*pm = af67: 这段代码中，m是一个无符号整数（32位），其十六进制表示为0x3E56AF67。pm是一个指向m的指针，但类型被转换为了unsigned short*。通过*pm可以访问pm指向的2个字节的内存内容。由于使用了hex标志，所以输出的结果是将pm指向的2个字节视为一个十六进制数，并打印出其值为af67。

这段代码主要展示了指针与数组的运算，以及不同类型之间的指针和转换操作。需要注意的是，在进行指针转换时，必须小心处理指针所指向的类型和内存布局，以避免出现未定义的行为或数据损坏。
*/

#include <iostream>
using namespace std;

int main()
{
    int a[][4]={1,3,5,7,9,11,13,15,17,19}; 
    int *p=*(a+1);
    p += 3;
    cout << "*p++ = " << *p++ << ",*p = " << *p << endl; 

    const char *pc = "Welcome to programming.", *r;
    long *q = (long *)pc;
    q++;
    r = (char *)q;

    cout << r << endl;

    unsigned int m = 0x3E56AF67;
    unsigned short *pm = (unsigned short *) &m;

    cout << "*pm = " <<  hex << *pm << endl;

    return 0;
}

// *p++ = 15,*p = 17
// to programming.
// *pm = af67
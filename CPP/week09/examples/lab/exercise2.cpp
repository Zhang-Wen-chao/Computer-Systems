/*
2. What is the result of the program below? What happens if you uncomment the commented line in function main()? Why? You need to explain the reason to a SA to pass the test.


(base) zwc@zwc-optiplex7010:~/Documents/linux_and_cpp/CPP/week09/examples/lab$ g++ exercise2.cpp 
exercise2.cpp: In function ‘int main()’:
exercise2.cpp:30:10: error: use of deleted function ‘ConstMember& ConstMember::operator=(const ConstMember&)’
   30 |     o1 = o2;
      |          ^~
exercise2.cpp:8:7: note: ‘ConstMember& ConstMember::operator=(const ConstMember&)’ is implicitly deleted because the default definition would be ill-formed:
    8 | class ConstMember
      |       ^~~~~~~~~~~
exercise2.cpp:8:7: error: non-static const member ‘const int ConstMember::m_a’, cannot use default assignment operator

这是什么意思？

这个错误意味着在代码中使用了被删除的赋值运算符函数，并且由于非静态的const成员变量存在，编译器无法为其生成默认的赋值运算符函数。

在代码中，你定义了一个名为`ConstMember`的类，并在该类中声明了一个非静态的const成员变量`m_a`。当一个类中有const成员变量时，默认的赋值运算符函数会被自动删除，因为它无法对const成员进行赋值操作。

然而，在`main()`函数中，你尝试将一个`ConstMember`对象`o2`赋值给另一个`ConstMember`对象`o1`，这导致了错误。编译器报告说赋值运算符函数被删除，因为它不能对`ConstMember`类中的非静态const成员变量进行赋值操作。

为了解决这个问题，你需要手动定义一个合适的赋值运算符函数，并在其中处理const成员变量的赋值。你可以通过重载赋值运算符函数来自定义对象之间的赋值操作，以适应你的需求。例如，你可以使用一个带有适当逻辑的自定义赋值运算符函数，或者将`m_a`声明为非const成员变量（如果适用）。

以下是一个例子，展示如何手动定义一个赋值运算符函数来处理含有const成员变量的类对象赋值操作：

```cpp
class ConstMember
{
public:
    const int m_a;

    // 构造函数
    ConstMember(int a) : m_a(a) {}

    // 自定义赋值运算符函数
    ConstMember& operator=(const ConstMember& other)
    {
        // 处理其他成员变量的赋值
        // ...

        return *this;
    }
};
```

通过定义适当的赋值运算符函数，你可以在类中处理const成员变量的赋值操作，并避免编译器错误。



然而，当一个类中有const成员变量时，这个默认的赋值运算符函数就会出现问题。const成员变量被定义为不可修改的，一旦初始化后，其值就不能再被修改。默认的赋值运算符函数试图逐成员复制，包括const成员变量，这会导致试图修改const成员变量的值，从而产生编译错误。
*/

#include <iostream>
using namespace std;

class ConstMember 
{
private:
    const int m_a;
public:
    ConstMember(int a) : m_a(a) {}

    void display() const
    {
        cout << "The value of the const member variable m_a is: " << m_a << endl;
    }
};


int main() 
{
    ConstMember o1{666};
    ConstMember o2{42};

    o1.display();
    o2.display();

    // o1 = o2;

    return 0;
}

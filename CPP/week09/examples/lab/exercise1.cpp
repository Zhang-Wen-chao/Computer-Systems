/*
Can the program below be run successfully? Why? How to modify it? Can the display() function be invoked by the Demo class instead of an object of Demo?
You need to explain the reason to a SA to pass the test.

In the modified code, the static member variable num is defined outside the class using Demo::num. Then, the display() function is invoked using Demo::display(), without creating an object of the Demo class.
在C++中，静态成员变量是类的所有对象共享的成员，而不是每个对象独有的成员。静态成员变量的存储空间是在程序的数据区分配的，而不是在每个对象的实例中分配。

因为静态成员变量是所有对象共享的，所以在使用之前需要对其进行初始化，以确保它有一个初始值。如果未对静态成员变量进行初始化，那么它的初始值是未定义的，可能是一个随机值。这可能会导致程序的不确定行为，因为不同对象之间的静态成员变量值可能不一致。

通过在类外部对静态成员变量进行初始化，可以确保所有对象共享的静态成员变量具有相同的初始值，从而避免潜在的错误和不确定性。

请注意，对于整型静态成员变量，如果未显式初始化，它们将默认初始化为0。但是为了代码的清晰性和可读性，建议显式初始化静态成员变量。对于其他类型的静态成员变量，如类类型或自定义类型，必须显式初始化，否则编译器将报错。
*/

// #include <iostream>
// using namespace std;

// class Demo 
// {
// public :
//     static int num;
//     void display() 
//     {
//         cout << "The value of the static member variable num is: " << num <<endl;
//     }
// };

// int main() 
// {
//     Demo obj;
//     obj.display();
//     return 0;
// }


#include <iostream>
using namespace std;

class Demo 
{
public:
    static int num;
    static void display() 
    {
        cout << "The value of the static member variable num is: " << num << endl;
    }
};

int Demo::num; // Define the static member variable outside the class

int main() 
{
    Demo::display(); // Invoke the display() function using the class name
    return 0;
}

/*
Could the program be compiled successfully? Why? Modify the program until it passes the compilation. Then run the program. What will happen? Explain the result to the SA.
否，程序将无法成功编译。代码中有几个问题需要解决：
第11行：不允许直接将原始指针p_reg分配给shared_ptr。要解决此问题，可以使用std:：make_shared从p_reg创建一个shared_ptr。
第14行：使用相同的p_reg原始指针将pshared重新定义为shared_ptr。当shared_ptr对象超出范围时，这将导致内存的双重删除。要解决此问题，请删除第14行中对pshared的重新定义。
第17行：pstr被分配了一个指向局部变量str的指针，当pstr超出范围时，这将导致未定义的行为。要解决此问题，可以使用std:：make_shared为str创建一个shared_ptr。
以下是解决这些问题的修改后的代码：
修改代码后，应该可以成功编译。然而，原始代码中存在内存泄漏，因为p_reg是用new分配的，但没有用delete解除分配。在修改后的代码中，在程序退出之前，通过删除来释放内存。
当您运行该程序时，它将打印存储在shared_ptr对象和字符串对象中的值，然后正常退出。
*/
// #include <iostream>
// #include <memory>

// using namespace std;

// int main()
// {
//     double *p_reg = new double(5);
//     shared_ptr<double> pd;
//     pd = p_reg;   // 11th line
//     pd = shared_ptr<double>(p_reg); 
//     cout << "*pd = " << *pd << endl;

//     shared_ptr<double> pshared = p_reg; // 14th line
//     shared_ptr<double> pshared(p_reg); 
//     cout << "*pshred = " << *pshared << endl;

//     string str("Hello World!");
//     shared_ptr<string> pstr(&str); 
//     cout << "*pstr = " << *pstr << endl;

//     return 0;
// }

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    double *p_reg = new double(5);
    shared_ptr<double> pd = make_shared<double>(*p_reg);
    cout << "*pd = " << *pd << endl;

    shared_ptr<double> pshared(pd);
    cout << "*pshared = " << *pshared << endl;

    string str("Hello World!");
    shared_ptr<string> pstr = make_shared<string>(str);
    cout << "*pstr = " << *pstr << endl;

    delete p_reg; // Don't forget to deallocate the memory allocated with new

    return 0;
}

/*
Are there any warnings in the program below when it is complied? What the warnings mean? Run the program regardless of warnings and explain the result to SA. Fix the warnings and run the program again. 

在上述程序中，有两个警告：

1. `exception of type 'MyException' will be caught`：此警告表示捕获到的异常类型`MyException`将被先前的异常处理程序`catch (const exception& e)`捕获。这是因为`MyException`是`std::exception`的派生类，它满足了`const exception&`类型的异常处理程序的条件。

2. `by earlier handler for 'std::exception'`：此警告指出先前的异常处理程序`catch (const exception& e)`可以捕获派生异常`MyException`，因此派生异常的处理程序`catch(const MyException& e)`将不会执行。

要消除这两个警告，可以按照以下步骤进行修改：

1. 调整异常处理程序的顺序，将派生异常`MyException`的处理程序放在`std::exception`的处理程序之前。

2. 修改`catch(const MyException& e)`的异常处理程序，使用`catch(const MyException& e)`而不是`catch(const MyException& e)`。


修复后的代码将异常处理程序的顺序进行了调整，确保先捕获派生异常`MyException`，再捕获基类异常`std::exception`。还将`what()`函数标记为`override`。

重新编译并运行这段代码将不再产生警告，并且输出结果将按预期进行输出。
*/

// #include <iostream>
// #include <string>

// using namespace std;

// class MyException : public exception
// {
// public:
//   MyException(const string& msg) : m_msg(msg)
//   {
//     cout << "MyException::MyException - set m_msg to:" << m_msg << endl;
//   }

//  ~MyException()
//  {
//     cout << "MyException::~MyException" << endl;
//  }

//  virtual const char* what() const throw () 
//  {
//     cout << "MyException::what" << endl;
//     return m_msg.c_str();
//  }

//  const string m_msg;
// };

// void throwDerivedException()
// {
//   cout << "throwDerivedException - thrown a derived exception" << endl;
//   string execptionMessage("MyException thrown");
//   throw (MyException(execptionMessage));
// }

// void illustrateDerivedExceptionCatch()
// {
//     cout << "illustrateDerivedExceptionsCatch - start" << endl;
//     try 
//     {
//         throwDerivedException();
//     }
//     catch (const exception& e)
//     {
//         cout << "illustrateDerivedExceptionsCatch - caught an std::exception, e.what:" << e.what() << endl;
//         // some additional code due to the fact that std::exception was thrown...
//     }
//     catch(const MyException& e)
//     {
//         cout << "illustrateDerivedExceptionsCatch - caught an MyException, e.what::" << e.what() << endl;
//         // some additional code due to the fact that MyException was thrown...
//     }

//     cout << "illustrateDerivedExceptionsCatch - end" << endl;
// }

// int main(int argc, char** argv)
// {
//     cout << "main - start" << endl;
//     illustrateDerivedExceptionCatch();
//     cout << "main - end" << endl;
//     return 0;
// }



#include <iostream>
#include <string>

using namespace std;

class MyException : public exception
{
public:
  MyException(const string& msg) : m_msg(msg)
  {
    cout << "MyException::MyException - set m_msg to: " << m_msg << endl;
  }

 ~MyException()
 {
    cout << "MyException::~MyException" << endl;
 }

 const char* what() const throw () override
 {
    cout << "MyException::what" << endl;
    return m_msg.c_str();
 }

 const string m_msg;
};

void throwDerivedException()
{
  cout << "throwDerivedException - throwing a derived exception" << endl;
  string exceptionMessage("MyException thrown");
  throw MyException(exceptionMessage);
}

void illustrateDerivedExceptionCatch()
{
    cout << "illustrateDerivedExceptionCatch - start" << endl;
    try 
    {
        throwDerivedException();
    }
    catch(const MyException& e)
    {
        cout << "illustrateDerivedExceptionCatch - caught a MyException, e.what: " << e.what() << endl;
        // some additional code due to the fact that MyException was thrown...
    }
    catch (const exception& e)
    {
        cout << "illustrateDerivedExceptionCatch - caught an std::exception, e.what: " << e.what() << endl;
        // some additional code due to the fact that std::exception was thrown...
    }

    cout << "illustrateDerivedExceptionCatch - end" << endl;
}

int main()
{
    cout << "main - start" << endl;
    illustrateDerivedExceptionCatch();
    cout << "main - end" << endl;
    return 0;
}

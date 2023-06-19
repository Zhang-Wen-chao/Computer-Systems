/*
Please point the errors of the following code and explain why to SA.

*/

class Base
{
  private:
    int x;
  protected:
    int y;
  public:
    int z;
  void funBase (Base& b)
  {
    ++x;
    ++y;
    ++z;
    ++b.x;
    ++b.y;
    ++b.z;
   }
};

/*
错误：在成员函数“void funBase（Base&）”中无法访问私有成员“int x”。
说明：私有成员“x”无法在“funBase”成员函数中直接访问，因为它在“Base”类中被声明为私有。私有成员只能在类本身内部访问，而不能由派生类或其他外部函数访问。
错误：在成员函数“void funBase（Base&）”中无法访问受保护的成员“int y”。
说明：与前面的错误类似，无法在“funBase”成员函数中直接访问受保护的成员“y”。受保护的成员可以由派生类和类本身访问，但不能由外部函数访问。
错误：“b.x”在此上下文中是私有的。
说明：不能在'funBase'成员函数中直接访问'Base'对象'b'的'x'成员，因为它在'Base'类中声明为private。对象的私有成员只能在声明它们的类中访问。
*/

class Derived:public Base
{
  public:
    void funDerived (Base& b, Derived& d)
    {
      ++x;
      ++y;
      ++z;
      ++b.x;
      ++b.y;
      ++b.z;
      ++d.x;
      ++d.y;
      ++d.z;
    }
};


/*
错误：“x”不是“Derived”的成员。
说明：变量“x”被声明为“Base”类中的私有成员。在派生类“derived”中无法直接访问它。基类的私有成员不由派生类继承，也不能直接访问。
错误：受保护的成员“int y”在“Derived”中不可访问。
说明：受保护的成员“y”由派生类“derived”继承。但是，它在成员函数“funDerived”中不可访问，因为没有为“Derived“指定访问说明符。由于'funDerived'是'Derived]的成员函数，因此它可以使用'y'标识符直接访问受保护的成员'y'。
错误：在“Base”中无法访问私有成员“int x”。
说明：在Derived类的成员函数funDerived中，不能直接访问Base类的私有成员x。私有成员只能在声明它们的类中访问。
*/


void fun(Base& b, Derived& d)
{
  ++x;
  ++y;
  ++z;
  ++b.x;
  ++b.y;
  ++b.z;
  ++d.x;
  ++d.y;
  ++d.z;
}

/*
错误：“x”不是“fun”的成员。
说明：变量“x”不能在函数“fun”中直接访问，因为它不是函数作用域的成员“x”是“Derived”类的成员，若要访问它，您需要一个“Deriveed”类的实例。
*/
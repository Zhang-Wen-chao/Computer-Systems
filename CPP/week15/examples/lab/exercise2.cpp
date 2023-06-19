/*
There are two declarations of two classes, Base and Derived. You are required to  implement the three kind of functions:
 (1) Equality operator == is declared as a friend function of the Base class. Two objects are equal if they have the same type and same value for a given set of their data members. If two objects have different types, throw a message ”The two objects have different types, they can not be compared.” as an exception. 
(2) Virtual equal member functions in Base and Derived class which check whether the data members have the same values in its own objects respectively. 
(3) void process(const Base&, const Base&) function is a normal function who checks  if the two objects are equal and handles the exception.


#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
protected:
    int bvalue;
public:
    Base(int i ) : bvalue(i) {}

    virtual bool equal(const Base& b) const;
    
    friend bool operator == (const Base&, const Base&);
};

class Derived : public Base
{
private:
    int dvalue;
public:
    Derived(int a, int b):Base(a), dvalue(b){}
    
    virtual bool equal(const Base& b) const override;
   
};

int main()
{
  Base b1(2);
  Base b2(2);
  
  Derived d1(1,2);
  Derived d2(2,2);

  process(b1,b2);
  process(d1,d2); 
  process(b1,d1);

  return 0;
}

Two Base type objects are equal.
Two Derived type objects are not equal because they have different values.
The two objects have different types , they can not be compared.

让我们逐步解释每个情况的原因：

1. 两个 `Base` 类型的对象相等：
   - `Base` 类定义了一个 `equal` 函数，该函数比较两个对象的 `bvalue` 值是否相等。
   - 在 `process(b1, b2)` 中，传递了两个 `Base` 对象 `b1` 和 `b2`，它们都具有相同的 `bvalue` 值为 2。
   - 因此，调用 `operator==` 函数进行比较时，两个对象被认为是相等的。

2. 两个 `Derived` 类型的对象不相等：
   - `Derived` 类继承自 `Base` 类，并添加了一个额外的私有成员 `dvalue`。
   - `Derived` 类重写了 `equal` 函数，它首先检查传入的对象是否可以转换为 `Derived` 类型，然后再比较 `Base` 类型的成员以及 `dvalue` 值。
   - 在 `process(d1, d2)` 中，传递了两个 `Derived` 对象 `d1` 和 `d2`。
   - 尽管它们都是 `Derived` 类型的对象，但它们的 `dvalue` 值不同。因此，它们被认为是不相等的。

3. 两个不同类型的对象无法比较：
   - 在 `process(b1, d1)` 中，传递了一个 `Base` 对象 `b1` 和一个 `Derived` 对象 `d1`。
   - 在 `operator==` 函数中，首先检查两个对象的类型是否相同。然而，`b1` 是 `Base` 类型，`d1` 是 `Derived` 类型。
   - 由于它们的类型不同，无法进行直接比较。因此，抛出一个异常，提示两个对象具有不同的类型，无法进行比较。

总结：
- 对于两个 `Base` 类型的对象，它们相等的条件是具有相同的 `bvalue` 值。
- 对于两个 `Derived` 类型的对象，它们相等的条件是具有相同的 `bvalue` 值和 `dvalue` 值，并且它们的类型都是 `Derived` 类型。
- 不同类型的对象无法进行比较，因为它们的成员不同，无法确定如何进行比较操作。在这种情况下，抛出一个异常来指示类型不匹配。
*/



#include <iostream>
#include <typeinfo>
using namespace std;

class Base
{
protected:
    int bvalue;
public:
    Base(int i) : bvalue(i) {}

    virtual bool equal(const Base& b) const
    {
        return typeid(*this) == typeid(b) && bvalue == b.bvalue;
    }
    
    friend bool operator==(const Base& b1, const Base& b2)
    {
        if (typeid(b1) != typeid(b2))
            throw runtime_error("The two objects have different types, they cannot be compared.");
        
        return b1.equal(b2);
    }
};

class Derived : public Base
{
private:
    int dvalue;
public:
    Derived(int a, int b) : Base(a), dvalue(b) {}
    
    bool equal(const Base& b) const override
    {
        const Derived* derivedPtr = dynamic_cast<const Derived*>(&b);
        if (derivedPtr == nullptr)
            return false;
        
        return Base::equal(b) && dvalue == derivedPtr->dvalue;
    }
};

void process(const Base& b1, const Base& b2)
{
    try
    {
        if (b1 == b2)
            cout << "Two Base type objects are equal." << endl;
        else
            cout << "Two Derived type objects are not equal because they have different values." << endl;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    Base b1(2);
    Base b2(2);
  
    Derived d1(1, 2);
    Derived d2(2, 2);

    process(b1, b2);
    process(d1, d2); 
    process(b1, d1);

    return 0;
}

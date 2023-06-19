/*
Run the following program, and explain the result to SA.


后面两个结果为0的原因是在基类Polygon中的area()函数的实现总是返回0。这个函数没有被派生类Rectangle和Triangle中的重写所覆盖。

在C++中，如果派生类重新定义了与基类中相同名称和签名的函数，则称为函数重写（Function Overriding）。在重写的情况下，调用函数时会根据对象的实际类型来确定要调用的函数版本。

然而，在这个示例中，基类Polygon中的area()函数没有被派生类重写。因此，无论对象的实际类型是什么，调用ppoly1->area()和ppoly2->area()时都会调用基类的area()函数，该函数总是返回0。

如果希望根据派生类的实际类型调用相应的area()函数，可以将基类中的area()函数声明为虚函数（virtual function）。虚函数通过在基类中使用virtual关键字进行声明，可以在派生类中进行重写，并在运行时根据对象的实际类型来确定要调用的函数版本。

下面是修改后的代码，将基类中的area()函数声明为虚函数：

通过将area()函数声明为虚函数，重写它的派生类（Rectangle和Triangle）可以提供它们自己的实现。这样，在调用ppoly1->area()和ppoly2->area()时，将根据对象的实际类型调用适当的函数版本，而不再返回0。
*/

#include <iostream>
using namespace std;

// class Polygon 
// {
//  protected:
//   int width, height;
//  public:
//   void set_values (int a, int b)
//    { width=a; height=b; }
//   int area()
//   { return 0;}
// };

class Polygon 
{
 protected:
  int width, height;
 public:
  void set_values(int a, int b)
   { width = a; height = b; }
  virtual int area() // 声明为虚函数
  { return 0; }
};


class Rectangle: public Polygon 
{
 public:
  int area()
   { return width * height; }
};

class Triangle: public Polygon 
{
 public:
  int area()
   { return width*height/2; }
};


int main () 
{
 Rectangle rect;
 Triangle trgl;
 Polygon * ppoly1 = &rect;
 Polygon * ppoly2 = &trgl;
 ppoly1->set_values (4,5);
 ppoly2->set_values (2,5);

  cout << rect.area() << endl;
 cout << trgl.area() << endl;
 cout << ppoly1->area() << endl;
 cout << ppoly2->area() << endl;
 return 0;
}
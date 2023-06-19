/*
Run the following program, and explain the result to SA. Is there any problem in the program?


关于这个项目中的任何问题，似乎没有任何重大问题。然而，有一个潜在的问题与内存管理有关。该程序使用带有new的动态内存分配来创建对象，但不使用delete来删除它们。这可能会导致内存泄漏，分配的内存无法释放。在这个简单的程序中，内存泄漏并不重要，因为程序在创建对象后立即结束。但是，在较大的程序中，或者在动态创建和销毁对象的情况下，使用delete正确地释放内存以避免内存泄漏是很重要的。
*/

// dynamic allocation and polymorphism
// #include <iostream>
// using namespace std;

// class Polygon 
// {
//  protected:
//   int width, height;
//  public:
//   Polygon (int a, int b) : width(a), height(b) {}
//   virtual int area (void) =0;
//   void printarea()
//    { cout << this->area() << '\n'; }
// };


// class Rectangle: public Polygon 
// {
//  public:
//   Rectangle(int a,int b) : Polygon(a,b) {}
//   int area()
//    { return width*height; }
// };

// class Triangle: public Polygon 
// {
//  public:
//   Triangle(int a,int b) : Polygon(a,b) {}
//   int area()
//    { return width*height/2; }
// };


// int main () 
// {
//  Polygon * ppoly = new Rectangle (4,5);
//  ppoly->printarea();
//  ppoly = new Triangle (2,5);
//  ppoly->printarea();

//  return 0;
// }




// dynamic allocation and polymorphism
#include <iostream>
using namespace std;

class Polygon 
{
 protected:
  int width, height;
 public:
  Polygon(int a, int b) : width(a), height(b) {}
  virtual ~Polygon() {} // 添加虚析构函数
  virtual int area() const = 0;
  void printarea() const
   { cout << this->area() << '\n'; }
};

class Rectangle: public Polygon 
{
 public:
  Rectangle(int a, int b) : Polygon(a, b) {}
  int area() const
   { return width * height; }
};

class Triangle: public Polygon 
{
 public:
  Triangle(int a, int b) : Polygon(a, b) {}
  int area() const
   { return width * height / 2; }
};

int main() 
{
 Polygon* ppoly = new Rectangle(4, 5);
 ppoly->printarea();
 delete ppoly; // 释放通过 new 创建的对象内存

 ppoly = new Triangle(2, 5);
 ppoly->printarea();
 delete ppoly; // 释放通过 new 创建的对象内存

 return 0;
}

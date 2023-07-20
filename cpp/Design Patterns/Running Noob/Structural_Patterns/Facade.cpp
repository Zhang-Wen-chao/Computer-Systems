#include <iostream>

class Shape {
public:
   virtual void draw() const = 0;
};

class Rectangle : public Shape {
public:
   void draw() const override {
      std::cout << "Rectangle::draw()" << std::endl;
   }
};

class Square : public Shape {
public:
   void draw() const override {
      std::cout << "Square::draw()" << std::endl;
   }
};

class Circle : public Shape {
public:
   void draw() const override {
      std::cout << "Circle::draw()" << std::endl;
   }
};

class ShapeMaker {
private:
   Shape* circle;
   Shape* rectangle;
   Shape* square;

public:
   ShapeMaker() {
      circle = new Circle();
      rectangle = new Rectangle();
      square = new Square();
   }

   void drawCircle() const {
      circle->draw();
   }

   void drawRectangle() const {
      rectangle->draw();
   }

   void drawSquare() const {
      square->draw();
   }

   ~ShapeMaker() {
      delete circle;
      delete rectangle;
      delete square;
   }
};

int main() {
   ShapeMaker shapeMaker;

   shapeMaker.drawCircle();
   shapeMaker.drawRectangle();
   shapeMaker.drawSquare();

   return 0;
}
#include <iostream>

class Shape {
public:
   virtual void draw() const = 0;
};

class Rectangle : public Shape {
public:
   void draw() const override {
      std::cout << "Shape: Rectangle" << std::endl;
   }
};

class Circle : public Shape {
public:
   void draw() const override {
      std::cout << "Shape: Circle" << std::endl;
   }
};

class ShapeDecorator : public Shape {
protected:
   Shape* decoratedShape;

public:
   ShapeDecorator(Shape* decoratedShape)
      : decoratedShape(decoratedShape) {}

   virtual void draw() const {
      decoratedShape->draw();
   }
};

class RedShapeDecorator : public ShapeDecorator {
public:
   RedShapeDecorator(Shape* decoratedShape)
      : ShapeDecorator(decoratedShape) {}

   void draw() const override {
      decoratedShape->draw();
      setRedBorder(decoratedShape);
   }

private:
   void setRedBorder(const Shape* decoratedShape) const {
      std::cout << "Border Color: Red" << std::endl;
   }
};

int main() {
   Shape* circle = new Circle();
   Shape* redCircle = new RedShapeDecorator(new Circle());
   Shape* redRectangle = new RedShapeDecorator(new Rectangle());

   std::cout << "Circle with normal border" << std::endl;
   circle->draw();

   std::cout << "\nCircle of red border" << std::endl;
   redCircle->draw();

   std::cout << "\nRectangle of red border" << std::endl;
   redRectangle->draw();

   delete circle;
   delete redCircle;
   delete redRectangle;

   return 0;
}
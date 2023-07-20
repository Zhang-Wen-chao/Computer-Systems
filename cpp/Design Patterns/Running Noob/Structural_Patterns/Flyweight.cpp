#include <iostream>
#include <map>

class Shape {
public:
   virtual void draw() const = 0;
};

class Circle : public Shape {
private:
   std::string color;
   int x;
   int y;
   int radius;

public:
   Circle(const std::string& color)
      : color(color), x(0), y(0), radius(0) {}

   void setX(int x) {
      this->x = x;
   }

   void setY(int y) {
      this->y = y;
   }

   void setRadius(int radius) {
      this->radius = radius;
   }

   void draw() const override {
      std::cout << "Circle: Draw() [Color: " << color
         << ", x: " << x << ", y: " << y << ", radius: " << radius << "]" << std::endl;
   }
};

class ShapeFactory {
private:
   static std::map<std::string, Shape*> circleMap;

public:
   static Shape* getCircle(const std::string& color) {
      auto it = circleMap.find(color);
      if (it != circleMap.end()) {
         return it->second;
      }
      else {
         Circle* circle = new Circle(color);
         circleMap.insert(std::make_pair(color, circle));
         std::cout << "Creating circle of color: " << color << std::endl;
         return circle;
      }
   }
};

std::map<std::string, Shape*> ShapeFactory::circleMap;

std::string getRandomColor() {
   std::string colors[] = { "Red", "Green", "Blue", "White", "Black" };
   return colors[rand() % 5];
}

int getRandomX() {
   return rand() % 100;
}

int getRandomY() {
   return rand() % 100;
}

int main() {
   srand(time(0));
   for (int i = 0; i < 20; ++i) {
      Shape* shape = ShapeFactory::getCircle(getRandomColor());
      Circle* circle = dynamic_cast<Circle*>(shape);
      if (circle) {
         circle->setX(getRandomX());
         circle->setY(getRandomY());
         circle->setRadius(100);
         circle->draw();
      }
   }
   return 0;
}
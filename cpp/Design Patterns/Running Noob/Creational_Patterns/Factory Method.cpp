#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
    void draw() {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() {
        std::cout << "Inside Circle::draw() method." << std::endl;
    }
};

class ShapeFactory {
public:
    Shape* getShape(std::string shapeType) {
        if (shapeType.empty()) {
            return nullptr;
        }
        if (shapeType == "CIRCLE") {
            return new Circle();
        } else if (shapeType == "RECTANGLE") {
            return new Rectangle();
        } else if (shapeType == "SQUARE") {
            return new Square();
        }
        return nullptr;
    }
};

int main() {
    ShapeFactory shapeFactory;

    // 获取 Circle 的对象，并调用它的 draw 方法
    Shape* shape1 = shapeFactory.getShape("CIRCLE");
    // 调用 Circle 的 draw 方法
    shape1->draw();

    // 获取 Rectangle 的对象，并调用它的 draw 方法
    Shape* shape2 = shapeFactory.getShape("RECTANGLE");
    // 调用 Rectangle 的 draw 方法
    shape2->draw();

    // 获取 Square 的对象，并调用它的 draw 方法
    Shape* shape3 = shapeFactory.getShape("SQUARE");
    // 调用 Square 的 draw 方法
    shape3->draw();

    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
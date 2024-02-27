#include <iostream>

// 抽象形状类
class Shape {
public:
    virtual void draw() = 0;
};

// 长方形类
class Rectangle : public Shape {
public:
    void draw() {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }
};

// 正方形类
class Square : public Shape {
public:
    void draw() {
        std::cout << "Inside Square::draw() method." << std::endl;
    }
};

// 圆形类
class Circle : public Shape {
public:
    void draw() {
        std::cout << "Inside Circle::draw() method." << std::endl;
    }
};

// 抽象颜色类
class Color {
public:
    virtual void fill() = 0;
};

// 红色类
class Red : public Color {
public:
    void fill() {
        std::cout << "Inside Red::fill() method." << std::endl;
    }
};

// 绿色类
class Green : public Color {
public:
    void fill() {
        std::cout << "Inside Green::fill() method." << std::endl;
    }
};

// 蓝色类
class Blue : public Color {
public:
    void fill() {
        std::cout << "Inside Blue::fill() method." << std::endl;
    }
};

// 抽象工厂类
class AbstractFactory {
public:
    virtual Shape* getShape(std::string shapeType) = 0;
    virtual Color* getColor(std::string color) = 0;
};

// 形状工厂类
class ShapeFactory : public AbstractFactory {
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
    
    Color* getColor(std::string color) {
        return nullptr;
    }
};

// 颜色工厂类
class ColorFactory : public AbstractFactory {
public:
    Shape* getShape(std::string shapeType) {
        return nullptr;
    }
    
    Color* getColor(std::string color) {
        if (color.empty()) {
            return nullptr;
        }
        if (color == "RED") {
            return new Red();
        } else if (color == "GREEN") {
            return new Green();
        } else if (color == "BLUE") {
            return new Blue();
        }
        return nullptr;
    }
};

// 工厂生产器类
class FactoryProducer {
public:
    static AbstractFactory* getFactory(std::string choice) {
        if (choice == "SHAPE") {
            return new ShapeFactory();
        } else if (choice == "COLOR") {
            return new ColorFactory();
        }
        return nullptr;
    }
};

int main() {
    // 获取形状工厂
    AbstractFactory* shapeFactory = FactoryProducer::getFactory("SHAPE");

    // 获取形状为 Circle 的对象
    Shape* shape1 = shapeFactory->getShape("CIRCLE");

    // 调用 Circle 的 draw 方法
    shape1->draw();

    // 获取形状为 Rectangle 的对象
    Shape* shape2 = shapeFactory->getShape("RECTANGLE");

    // 调用 Rectangle 的 draw 方法
    shape2->draw();

    // 获取形状为 Square 的对象
    Shape* shape3 = shapeFactory->getShape("SQUARE");

    // 调用 Square 的 draw 方法
    shape3->draw();

    // 获取颜色工厂
    AbstractFactory* colorFactory = FactoryProducer::getFactory("COLOR");

    // 获取颜色为 Red 的对象
    Color* color1 = colorFactory->getColor("RED");

    // 调用 Red 的 fill 方法
    color1->fill();

    // 获取颜色为 Green 的对象
    Color* color2 = colorFactory->getColor("GREEN");

    // 调用 Green 的 fill 方法
    color2->fill();

    // 获取颜色为 Blue 的对象
    Color* color3 = colorFactory->getColor("BLUE");

    // 调用 Blue 的 fill 方法
    color3->fill();

    delete shape1;
    delete shape2;
    delete shape3;
    delete color1;
    delete color2;
    delete color3;
    
    delete shapeFactory;
    delete colorFactory;

    return 0;
}
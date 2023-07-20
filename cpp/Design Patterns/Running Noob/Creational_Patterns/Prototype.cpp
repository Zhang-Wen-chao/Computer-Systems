#include <iostream>
#include <unordered_map>

class Shape {
public:
    virtual void draw() = 0;
    virtual std::string getType() = 0;
    virtual std::string getId() {
        return id;
    }
    virtual void setId(std::string id) {
        this->id = id;
    }
    virtual Shape* clone() = 0;

protected:
    std::string id;
    std::string type;
};

class Rectangle : public Shape {
public:
    Rectangle() {
        type = "Rectangle";
    }

    void draw() override {
        std::cout << "Inside Rectangle::draw() method." << std::endl;
    }

    std::string getType() override {
        return type;
    }

    Shape* clone() override {
        return new Rectangle(*this);
    }
};

class Square : public Shape {
public:
    Square() {
        type = "Square";
    }

    void draw() override {
        std::cout << "Inside Square::draw() method." << std::endl;
    }

    std::string getType() override {
        return type;
    }

    Shape* clone() override {
        return new Square(*this);
    }
};

class Circle : public Shape {
public:
    Circle() {
        type = "Circle";
    }

    void draw() override {
        std::cout << "Inside Circle::draw() method." << std::endl;
    }

    std::string getType() override {
        return type;
    }

    Shape* clone() override {
        return new Circle(*this);
    }
};

class ShapeCache {
private:
    static std::unordered_map<std::string, Shape*> shapeMap;

public:
    static Shape* getShape(std::string shapeId) {
        Shape* cachedShape = shapeMap[shapeId];
        return cachedShape->clone();
    }

    static void loadCache() {
        Circle* circle = new Circle();
        circle->setId("1");
        shapeMap[circle->getId()] = circle;

        Square* square = new Square();
        square->setId("2");
        shapeMap[square->getId()] = square;

        Rectangle* rectangle = new Rectangle();
        rectangle->setId("3");
        shapeMap[rectangle->getId()] = rectangle;
    }
};

std::unordered_map<std::string, Shape*> ShapeCache::shapeMap;

int main() {
    ShapeCache::loadCache();

    Shape* clonedShape = ShapeCache::getShape("1");
    std::cout << "Shape : " << clonedShape->getType() << std::endl;

    Shape* clonedShape2 = ShapeCache::getShape("2");
    std::cout << "Shape : " << clonedShape2->getType() << std::endl;

    Shape* clonedShape3 = ShapeCache::getShape("3");
    std::cout << "Shape : " << clonedShape3->getType() << std::endl;

    return 0;
}
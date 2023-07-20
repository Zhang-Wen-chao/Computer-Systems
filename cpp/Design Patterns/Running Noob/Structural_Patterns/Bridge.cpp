#include <iostream>

class DrawAPI {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: red, radius: "
            << radius <<", x: " << x << ", " << y << "]" << std::endl;
    }
};

class GreenCircle : public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: green, radius: "
            << radius <<", x: " << x << ", " << y << "]" << std::endl;
    }
};

class Shape {
protected:
    DrawAPI* drawAPI;
public:
    Shape(DrawAPI* drawAPI) {
        this->drawAPI = drawAPI;
    }

    virtual void draw() = 0;
};

class Circle : public Shape {
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI) {
        this->x = x;  
        this->y = y;  
        this->radius = radius;
    }

    void draw() override {
        drawAPI->drawCircle(radius, x, y);
    }
};

// 新增代码
class BlueCircle : public DrawAPI {
public:
    void drawCircle(int radius, int x, int y) override {
        std::cout << "Drawing Circle[ color: blue, radius: "
            << radius <<", x: " << x << ", " << y << "]" << std::endl;
    }
};

int main() {
    DrawAPI* redCircle = new RedCircle();
    DrawAPI* greenCircle = new GreenCircle();
    DrawAPI* blueCircle = new BlueCircle(); // 新增代码

    Shape* shape1 = new Circle(100, 100, 10, redCircle);
    Shape* shape2 = new Circle(100, 100, 10, greenCircle);
    Shape* shape3 = new Circle(100, 100, 10, blueCircle); // 新增代码

    shape1->draw();
    shape2->draw();
    shape3->draw(); // 新增代码

    delete redCircle;
    delete greenCircle;
    delete blueCircle;
    delete shape1;
    delete shape2;
    delete shape3;

    return 0;
}
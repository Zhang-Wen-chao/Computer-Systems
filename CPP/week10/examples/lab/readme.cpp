/*
overload + and << for your own defined class
*/
#include <iostream>

class MyClass {
private:
    int value;

public:
    MyClass(int val) : value(val) {}

    // Overloading the + operator
    MyClass operator+(const MyClass& other) const {
        return MyClass(value + other.value);
    }

    // Overloading the << operator
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << obj.value;
        return os;
    }
};

int main() {
    MyClass obj1(5);
    MyClass obj2(10);

    MyClass obj3 = obj1 + obj2;
    std::cout << "Result of addition: " << obj3 << std::endl;

    return 0;
}

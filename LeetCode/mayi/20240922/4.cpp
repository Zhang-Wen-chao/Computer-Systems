#include <iostream>

class MyClass {
public:
    MyClass() {
        std::cout << "Con" << std::endl;
    }
    ~MyClass(){
        std::cout<< "Des" << std::endl;
    }
};

int main(){
    MyClass *arr = new MyClass[2];
    delete[] arr;
    return 0;
}
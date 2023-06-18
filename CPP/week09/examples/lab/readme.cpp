/*
Create a simple class. Please try to test:

* access a private member
* modify a const data member
* modify a data member in a const function
* initialize a const data member
*/

#include <iostream>

class MyClass {
private:
    int privateMember;
    const int constDataMember;
    mutable int mutableMember; // Mutable member variable
public:
    MyClass(int value) : constDataMember(value), mutableMember(0) {
        privateMember = 10;
    }
    
    int getPrivateMember() {
        return privateMember;
    }
    
    void modifyConstDataMember() {
        const_cast<int&>(constDataMember) = 20;
    }
    
    void modifyDataMemberInConstFunction() const {
        mutableMember = 20; // Modify the mutable member variable
    }
    
    int getConstDataMember() const {
        return constDataMember;
    }
};

int main() {
    MyClass obj(5);
    
    // Accessing a private member
    std::cout << "Private member value: " << obj.getPrivateMember() << std::endl;
    
    // Modifying a const data member
    obj.modifyConstDataMember();
    
    // Modifying a data member in a const function
    obj.modifyDataMemberInConstFunction();
    
    // Accessing a modified data member in a const function
    std::cout << "Modified data member value in const function: " << obj.getPrivateMember() << std::endl;
    
    // Initializing a const data member
    std::cout << "Const data member value: " << obj.getConstDataMember() << std::endl;
    
    return 0;
}

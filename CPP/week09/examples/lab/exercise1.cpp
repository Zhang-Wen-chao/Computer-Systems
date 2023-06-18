/*
Can the program below be run successfully? Why? How to modify it? Can the display() function be invoked by the Demo class instead of an object of Demo?
You need to explain the reason to a SA to pass the test.

In the modified code, the static member variable num is defined outside the class using Demo::num. Then, the display() function is invoked using Demo::display(), without creating an object of the Demo class.
*/

// #include <iostream>
// using namespace std;

// class Demo 
// {
// public :
//     static int num;
//     void display() 
//     {
//     cout << "The value of the static member variable num is: " << num <<endl;
//     }
// };

// int main() 
// {
//     Demo obj;
//     obj.display();
//     return 0;
// }


#include <iostream>
using namespace std;

class Demo 
{
public:
    static int num;
    static void display() 
    {
        cout << "The value of the static member variable num is: " << num << endl;
    }
};

int Demo::num; // Define the static member variable outside the class

int main() 
{
    Demo::display(); // Invoke the display() function using the class name
    return 0;
}

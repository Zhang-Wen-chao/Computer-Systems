/*
Suppose there is a default arguments function to display a square of any character and the test program as follows.
Are there any bugs in the function or main? Fix them and run the program correctly.


Explanation of the fixes:

In C++, default arguments can only be provided in the function declaration (header), not in the function definition (implementation). Therefore, we remove the default arguments from the function definition.
The line displaySquare(,'&'); contains a syntax error. The second argument is missing. To fix this, we remove the incomplete line.
The line displaySquare(2); should work fine now, as it will use the default character ‘*’ and the side length of 2.
After making these fixes, you can compile and run the program. It should execute correctly without any bugs.
*/

// #include <iostream>
// using namespace std;

// void displaySquare(int side = 4, char filledChar = '*');

// int main()
// {
//     displaySquare();
//     displaySquare(10,'#');
//     displaySquare(,'&');
//     displaySquare(2);

//     return 0;
// }

// void displaySquare(int side = 4, char filledChar = '*')
// {
//     for(int i = 0; i < side; i++)
//     {
//         for(int j = 0; j < side; j++)
//             cout << filledChar;
//         cout << "\n";
//     }
        
// }


#include <iostream>
using namespace std;

void displaySquare(int side = 4, char filledChar = '*');

int main()
{
    displaySquare();
    displaySquare(10, '#');
    displaySquare(2);

    return 0;
}

void displaySquare(int side, char filledChar)
{
    for(int i = 0; i < side; i++)
    {
        for(int j = 0; j < side; j++)
            cout << filledChar;
        cout << "\n";
    }
        
}

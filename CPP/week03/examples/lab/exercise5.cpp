/*
Run the following source code and explain the result.
You need to explain the reason to a SA to pass the test.
*/

#include <iostream>
using namespace std;

int main()
{
    int n,fa;

    do{
        fa *= n;
        n++;
    }while(n <= 10);

    cout << "fa = " << fa << endl;

    return 0;
}
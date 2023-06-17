/*
Run the following source code and explain the result.

You need to explain the reason to a SA to pass the test.



The reason `f1` is not equal to `f2` in the given code is due to the limitations of floating-point arithmetic and precision.

In the code, `f1` is initialized as 1.0f, which is a single precision floating-point value. `f2` is calculated by adding `a` (0.1f) to itself ten times. 

However, floating-point numbers cannot represent all decimal values exactly, and there can be rounding errors and precision limitations in floating-point arithmetic. This is because floating-point numbers are stored in a finite number of bits and cannot precisely represent all real numbers.

In this case, the sum `f2` may not exactly equal 1.0 due to accumulated rounding errors during the addition operations. The comparison `f1 == f2` checks for exact equality, which fails due to the precision differences.

To compare floating-point numbers, it is generally recommended to use an epsilon or tolerance value to check if the difference between the values is within an acceptable range. For example, you can modify the code as follows:

```cpp
#include <iostream>
#include <cmath> // for fabs

int main() {
    std::cout << std::fixed;

    float f1 = 1.0f;
    std::cout << "f1 = " << f1 << std::endl;

    float a = 0.1f;
    float f2 = a + a + a + a + a + a + a + a + a + a;
    std::cout << "f2 = " << f2 << std::endl;

    float epsilon = 0.0001f; // tolerance for comparison
    if (std::fabs(f1 - f2) <= epsilon) {
        std::cout << "f1 is approximately equal to f2" << std::endl;
    } else {
        std::cout << "f1 is not equal to f2" << std::endl;
    }

    return 0;
}
```

By introducing an epsilon value, you can compare the difference between `f1` and `f2` to determine if they are approximately equal. The specific epsilon value depends on the desired level of precision for your comparison.
*/

#include <iostream>
using namespace std;

int main() 
{
    cout << fixed;
    float f1 = 1.0f;
    cout<<"f1 = "<<f1<<endl;

    float a = 0.1f;
    float f2 = a+a+a+a+a+a+a+a+a+a;
    cout<<"f2 = "<<f2<<endl;
    
    if(f1 == f2)
        cout << "f1 = f2" << endl;
    else
        cout << "f1 != f2" << endl;

    return 0;
}
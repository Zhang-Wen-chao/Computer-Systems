/*
Compile and run the following source code. Is the output exactly match what you expect? If not, explain why?


The output you provided indicates that sum10x is displayed as 1, mul10x is displayed as 1, (sum10x == 1) is displayed as 0, and (mul10x == 1) is displayed as 1. Let’s analyze why this occurs:

sum10x:
In the code, sum10x is calculated by adding f to itself ten times. Since f is initialized with 0.1f, the expected result of the sum is 1.0. However, due to the limitations of floating-point precision, the actual sum may have a slight rounding error. In this case, it appears that the sum is evaluated as exactly 1.0 when displayed, likely due to rounding during the conversion to a string for output.

mul10x:
mul10x is calculated by multiplying f by 10. Since f is 0.1f, the expected result of the multiplication is 1.0. Again, due to floating-point precision, there can be small rounding errors. However, in this case, it appears that the multiplication result is evaluated as exactly 1.0 when displayed.

(sum10x == 1):
The comparison (sum10x == 1.0) checks if sum10x is exactly equal to 1.0. However, as mentioned earlier, floating-point numbers are subject to precision limitations, and the sum may have a slight rounding error. In this case, the comparison evaluates to false (0) because the rounded value of sum10x is not exactly 1.0.

(mul10x == 1):
The comparison (mul10x == 1.0) checks if mul10x is exactly equal to 1.0. Since mul10x is evaluated as exactly 1.0 when displayed, the comparison evaluates to true (1).

Overall, the discrepancy between the displayed values and the comparison results is due to the way floating-point numbers are represented and the precision limitations involved in their calculations.

Overall, it’s important to be aware of the limitations of floating-point arithmetic and the potential for small differences when working with floating-point numbers. Comparisons of floating-point numbers should be done with caution, considering appropriate tolerance or epsilon values instead of exact equality checks.
*/

#include <iostream>

using std::cout;
using std::endl;

int main() {
    int num1 = 1234567890;
    int num2 = 1234567890;
    int sum = num1 + num2;
    cout << "sum = " << sum << endl;

    float f1 = 1234567890.0f;
    float f2 = 1.0f;
    float fsum = f1 + f2;
    cout << "fsum = " << fsum << endl;
    cout << "(fsum == f1) is " << (fsum == f1) << endl;

    float f = 0.1f;
    float sum10x = f + f + f + f + f + f + f + f + f + f;
    float mul10x = f * 10;

    cout<<"sum10x = "<< sum10x << endl;
    cout<<"mul10x = "<< mul10x << endl;
    cout<<"(sum10x == 1) is "<< (sum10x == 1.0) << endl;
    cout<<"(mul10x == 1) is "<< (mul10x == 1.0) << endl;
    return 0;
}
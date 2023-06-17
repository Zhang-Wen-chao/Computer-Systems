/*
Run the following source code and explain the result.
You need to explain the reason to a SA to pass the test.

这段代码中的循环条件 n >= 0 使用了无符号整数类型 size_t。无符号整数类型不支持负数，所以当 n 的值减到 0 后，继续进行自减操作会导致整数溢出，即 n 的值会变成一个很大的正整数，而不是变为负数。

由于循环条件始终为真（n >= 0 总是为真），循环会无限地继续执行下去，导致代码陷入无限循环。这是因为 size_t 是一个无符号整数类型，在溢出后会重新从最大值开始计数，而不是变为负数。

要修复这个问题，可以将循环条件改为 n > 0，这样当 n 的值为 0 时，循环就会停止。另外，使用有符号整数类型（如 int）也可以避免这个问题。
*/

#include <iostream>
using namespace std;

int main()
{
    for(size_t n = 2; n >= 0; n--)
    // for(int n = 2; n >= 0; n--)
        cout << "n = " << n << "  ";

    return 0;
    
}

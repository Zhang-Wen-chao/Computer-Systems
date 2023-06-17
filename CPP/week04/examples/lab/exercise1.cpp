/*
First, complete the code, then run the program and explain the result to SA. If it has bugs, fix them.

在输出 sizeof(title) 和 strlen(title) 的结果时，你会注意到结果并不一致。

这是因为 sizeof 运算符和 strlen 函数计算长度的方式是不同的。

sizeof 运算符返回的是编译时数组或类型的大小，它计算的是变量或类型所占用的内存字节数。对于字符数组 title，它在编译时会计算数组的大小，包括字符串的内容和结尾的空字符 '\0'。所以 sizeof(title) 返回的是数组的大小，即 29 字节。

strlen 函数用于计算以空字符 '\0' 结尾的字符串的实际长度，它在运行时遍历字符串中的字符，直到遇到第一个空字符为止，然后返回字符的数量，不包括空字符。对于字符数组 title，它包含了 “ChartGPT is an awesome tool.” 这个字符串以及结尾的空字符 '\0'。所以 strlen(title) 返回的是字符串的长度，即 28。

同样的情况也适用于 direction 数组。

sizeof(direction) 返回的是数组 direction 的大小，即 5 字节。

strlen(direction) 在 direction 数组中查找空字符 '\0' 之前的字符数量，即 “L”, “R”, “U” 和 “D” 四个字符，所以返回的是 4。

因此，sizeof 运算符和 strlen 函数给出的结果可能不同，因为它们计算的内容和方式不同。
*/

// #include <iostream>
// #include <string.h>
// using namespace std;

// int main()
// {
//     int cards[4]{};
//     int hands[4];

//     int price[] = {2.8,3.7,5,9};
//     char direction[4] {'L',82,'U',68};

//     char title[] = "ChartGPT is an awesome tool.";

//     cout << "sizeof(cards) = " << sizeof(cards) << ",sizeof of cards[0] = " << sizeof(cards[0]) << endl;
//     cout << "sizeof(price) = " << sizeof(price) << ",sizeof of price[0] = " << sizeof(price[1]) << endl;
//     cout << "sizeof(direction) = " << sizeof(direction) << ",length of direction = " << strlen(direction) << endl;
//     cout << "sizeof(title) = " << sizeof(title) << ",length of title = " << strlen(title) << endl;

//     //Print the value and address of each element in cards and hands respectively.

//     return 0;
// }




#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int cards[4]{};
    int hands[4];

    float price[] = {2.8, 3.7, 5, 9};
    char direction[5] = {'L', static_cast<char>(82), 'U', static_cast<char>(68), '\0'};

    char title[] = "ChartGPT is an awesome tool.";

    cout << "sizeof(cards) = " << sizeof(cards) << ", sizeof of cards[0] = " << sizeof(cards[0]) << endl;
    cout << "sizeof(price) = " << sizeof(price) << ", sizeof of price[0] = " << sizeof(price[0]) << endl;
    cout << "sizeof(direction) = " << sizeof(direction) << ", length of direction = " << strlen(direction) << endl;
    cout << "sizeof(title) = " << sizeof(title) << ", length of title = " << strlen(title) << endl;

    // Print the value and address of each element in cards and hands respectively.
    for (int i = 0; i < 4; i++) {
        cout << "cards[" << i << "] = " << cards[i] << ", address: " << &cards[i] << endl;
    }

    for (int i = 0; i < 4; i++) {
        cout << "hands[" << i << "] = " << hands[i] << ", address: " << &hands[i] << endl;
    }

    return 0;
}

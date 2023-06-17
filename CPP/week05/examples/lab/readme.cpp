/*
allocate memory for an array string, modify elements by integer values one by one, then print out the result as a string. Please try to modify the element out of range and see what will happen.
*/
#include <iostream>
#include <cstring>

int main() {
    const int ARRAY_SIZE = 5;
    const int MAX_ELEMENT_LENGTH = 20;

    char** array = new char*[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = new char[MAX_ELEMENT_LENGTH];
        std::memset(array[i], 0, MAX_ELEMENT_LENGTH); // 初始化字符串为零
    }

    // 修改元素
    array[0] = "Hello";
    array[1] = "World";
    array[2] = "Foo";
    array[3] = "Bar";
    array[4] = "Baz";

    // 打印结果
    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << array[i] << std::endl;
    }

    // 尝试修改超出范围的元素
    array[5] = "Oops";

    // 释放内存
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}

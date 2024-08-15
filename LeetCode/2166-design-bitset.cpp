#include <iostream>
#include <vector>

class BitMap {
private:
std::vector<unsigned int> bitmap;
int size;

public:
BitMap(int n) {
    size = n;
    bitmap.resize((n + 31) / 32, 0);
}

void setBit(int num) {
    int index = num / 32;
    int offset = num % 32;
    bitmap[index] |= (1 << offset);
}

void resetBit(int num) {
    int index = num / 32;
    int offset = num % 32;
    bitmap[index] &= ~(1 << offset);
}

bool getBit(int num) {
    int index = num / 32;
    int offset = num % 32;
    return (bitmap[index] & (1 << offset)) != 0;
}

int find(int x) {
    int index = x / 32;
    int offset = x % 32;
    return (bitmap[index] >> offset) & 1;
}
};

int main() {
    int n = 1000; // 假设要存储1000位数
    BitMap bitmap(n);

    // 设置第10位为1
    bitmap.setBit(10);

    // 获取第10位的值
    bool bitValue = bitmap.getBit(10);
    std::cout << "The value of bit 10 is: " << bitValue << std::endl;

    // 查找第10位的状态
    int bitState = bitmap.find(10);
    std::cout << "The state of bit 10 is: " << bitState << std::endl;

    return 0;
}
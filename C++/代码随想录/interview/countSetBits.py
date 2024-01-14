def countBits(n):
    count = 0
    while n:
        n &= n - 1  # 消除最右边的1
        count += 1
    return count

# 测试用例
print(countBits(5))  # 二进制101，输出: 2
print(countBits(7))  # 二进制111，输出: 3
print(countBits(0))  # 二进制0，输出: 0

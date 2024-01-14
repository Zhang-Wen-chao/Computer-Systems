def monotoneIncreasingDigits(N):
    digits = list(str(N))
    n = len(digits)
    mark = n

    for i in range(n - 1, 0, -1):
        if digits[i] < digits[i - 1]:
            mark = i
            digits[i - 1] = str(int(digits[i - 1]) - 1)

    for i in range(mark, n):
        digits[i] = '9'

    return int(''.join(digits))

# 测试用例
print(monotoneIncreasingDigits(10))  # 应该输出 9
print(monotoneIncreasingDigits(1234))  # 应该输出 1234
print(monotoneIncreasingDigits(332))  # 应该输出 299

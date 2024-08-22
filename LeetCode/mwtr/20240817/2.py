# https://mp.weixin.qq.com/s/HTEK_x6fK2CTVjD1jFS-GQ
# 不看了，脑壳疼。

# 小美对 gcd (最大公约数) 很感兴趣，她会询问你t次。

# 每次询问给出一个大于1的正整数n，你是否找到一个数字 m (2 ≤ m ≤ n)，使得 gcd(n,m)为素数。

# 输入描述
# 每个测试文件均包含多组测试数据。第一行输入一个整数 T (1 ≤ T ≤ 100) 代表数据组数，每组测试数据描述如下：

# 在一行上输入一个整数 n (2 ≤ n ≤ 10^5)代表给定的数字。

# 输出描述
# 对于每一组测试数据，在一行上输出一个整数，代表数字m。 如果有多种合法答案，您可以输出任意一种。

# 输入：

# 2
# 114
# 15
# 输出：

# 57
# 5
import math

def main():
    test_cases = int(input())

    while test_cases > 0:
        test_cases -= 1
        number = int(input())
        is_prime = True

        for divisor in range(2, int(math.sqrt(number)) + 1):
            if number % divisor == 0:
                print(divisor)
                is_prime = False
                break

        if is_prime:
            print(number)

if __name__ == "__main__":
    main()

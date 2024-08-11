# 小美对偶数因子很感兴趣，她将进行T次询问，每次都会给出一个正整数x,请你告诉她x是否存在至少一个偶数因子。
# 也就是说x是否存在某个因子是偶数。说明：y是x的因子，当且仅当x mod y = 0。
# 输入：
# 2
# 1
# 4
# 输出
# NO
# YES
# 说明，输入的第一行2是指2组数据，1不存在偶数因子，4存在偶数因子。

def has_even_factor(x):
    if x % 2 == 0:
        return "YES"
    else:
        return "NO"
    
T = int(input())
results = []

for i in range(T):
    x = int(input())
    results.append(has_even_factor(x))

for result in results:
    print(result)
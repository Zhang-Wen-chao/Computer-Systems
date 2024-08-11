# 小美准备登录美团，需要输入密码，小美忘记了密码，只记得密码可能是n个字符串中的一个。
# 小美会按照密码的长度从小到大一次尝试每个字符串，对于相同长度的字符串，小美随机尝试，并且相同的密码只会尝试一次。
# 小美想知道，她最少需要尝试多少次才能登录成功，最多需要尝试多少次才能登录成功。
# 小美不会重新尝试已经运行过的字符串。成功登录后会立即停止尝试。
# 输入描述：
# 第一行输入一个整数n(1<=n<=1000)代表密码字符的个数。
# 第二行输入一个只由小写字母组成的字符串s(1<=|s|<=1000）代表正确的密码。
# 接下来n行，每行输入一个长度不超过1000的字符串，代表小美记得的密码。
# 输出描述：
# 在一行上输出两个整数，表示最少和最多尝试次数。

# 示例1
# 输入：
# 4
# ab
# abc
# ab
# ac
# ac
# 输出：
# 1 2
# 说明：小美可能按照['ab', 'ac', 'abc']的顺序，第一次就成功，也可能按照['ac', 'ab', 'abc'] 的顺序尝试，第二次尝试成功。小美在尝试'ac'发现不正确后也不会继续尝试'ac'。

def calculate_attempts(n, correct_password, password_list):
    password_list = list(set(password_list))
    password_list.sort(key=len)
    min_attempts = 0
    max_attempts = 0
    same_length_count = 0
    total_attempts = 0

    for password in password_list:
        if len(password) < len(correct_password):
            total_attempts += 1
        if len(password) == len(correct_password):
            same_length_count += 1

        min_attempts = total_attempts + 1
        max_attempts = total_attempts + same_length_count
    return min_attempts, max_attempts

n = int(input())
correct_password = input().strip()
password_list = [input().strip() for _ in range(n)]

min_attempts, max_attempts = calculate_attempts(n, correct_password, password_list)
print(min_attempts, max_attempts)
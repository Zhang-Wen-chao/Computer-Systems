# 给你一个由若干a和b组成的字符串s，请你计算并返回将该字符串分割成两个非空字符串所能获得的最大得分。得分是左字符串中a的数量加上右字符串中b的数量。
# 输入
# abbbab
# 输出
# 5
# 输入
# aabbb
# 输出
# 5
# 输入
# bbbb
# 输出
# 3
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param str string字符串 
# @return int整型
#
class Solution:
    def StringSplit(self , str ):
        # write code here
        n = len(str)
        prefix_a = [0] * n
        prefix_b = [0] * n
        if str[0] == 'a':
            prefix_a[0] = 1
        else:
            prefix_b[0] = 1
        for i in range(1,n):
            if str[i] == 'a':
                prefix_a[i] = prefix_a[i-1] +1
                prefix_b[i] = prefix_b[i-1]
            else:
                prefix_b[i] = prefix_b[i-1] +1
                prefix_a[i] = prefix_a[i-1]

        total_b = prefix_b[-1]
        max_score = 0
        for i in range(1,n):
            left_a = prefix_a[i-1]
            right_b = total_b - prefix_b[i-1]
            score = left_a + right_b
            max_score = max(max_score, score)
        return max_score
# 最初，你站在无限数轴位置startPos处。给你两个正整数startPos和endPos。
# 在一次移动中，你可以向左或向右移动一个位置。给你一个正整数k，返回从startPos出发，恰好移动k步并到达endPos的不同方法书目。答案可能很大，结果对10^9+7取余。如果所执行移动的顺序不完全相同，则认为两种方法不同。
# 输入
# 1，2，3
# 输出
# 3
# 说明3种路径，从1到2都是3步。
# 1，2，3，2
# 1，2，1，2
# 1，0，1，2
# 输入
# 2，5，10
# 输出
# 0
# 说明
# 不存在从2到5且恰好移动10步的方法。
# 核心代码模式，Python
# def numberofways（self，startPos，endPos，k）
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param startPos int整型 
# @param endPos int整型 
# @param k int整型 
# @return int整型
#
class Solution:
    def numberOfWays(self , startPos: int, endPos: int, k: int) -> int:
        # write code here
        MOD = 10**9 +7
        d = abs(endPos - startPos)
        if d> k or (k-d) %2 != 0:
            return 0
        x = (k+d) //2
        max_k = k
        factorial = [1] * (max_k +1)
        inv_factorial = [1] * (max_k + 1)
        for i in range(1, max_k +1):
            factorial[i] = factorial[i-1]* i % MOD
        inv_factorial[max_k] = pow(factorial[max_k], MOD-2, MOD)
        for i in range(max_k-1, -1, -1):
            inv_factorial[i] = inv_factorial[i+1] * (i+1) % MOD
        result = factorial[k] * inv_factorial[x] % MOD
        result = result * inv_factorial[k-x] % MOD
        return result


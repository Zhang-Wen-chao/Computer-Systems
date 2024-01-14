def findContentChildren(g, s):
    g.sort()
    s.sort()
    child_i = cookie_j = 0
    while child_i < len(g) and cookie_j < len(s):
        if g[child_i] <= s[cookie_j]:
            child_i += 1
        cookie_j += 1
    return child_i

# 测试用例
g = [1, 2, 3]  # 孩子的贪心指数
s = [1, 1]     # 饼干的大小
print(findContentChildren(g, s))  # 输出应该是 1

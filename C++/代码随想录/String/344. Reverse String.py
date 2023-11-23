def reverseString(self, s: List[str]) -> None:
    s[:] = s[::-1]

# 测试用例
test_case = ["h","e","l","l","o"]
reverseString(test_case)
print(test_case)  # 应输出: ['o', 'l', 'l', 'e', 'h']

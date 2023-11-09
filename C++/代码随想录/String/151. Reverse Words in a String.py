def reverseWords(s: str) -> str:
    # 分割字符串，去除空字符串，然后反转列表
    words = [word for word in s.split(" ") if word]
    return " ".join(reversed(words))

# 测试用例
test_cases = [
    "the sky is blue",
    "  hello world  ",
    "a good   example",
    "  Bob    Loves  Alice   ",
    "Alice does not even like bob"
]

for test in test_cases:
    print(f"'{test}' -> '{reverseWords(test)}'")

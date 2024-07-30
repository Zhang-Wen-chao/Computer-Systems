def modifyString(s: str) -> str:
    # 将字符串转为列表，方便修改
    s = list(s)
    
    for i in range(len(s)):
        if s[i] == '?':
            # 查找一个可以替换 '?' 的字符
            for char in 'abcdefghijklmnopqrstuvwxyz':
                # 确保不与前后字符相同
                if (i > 0 and s[i-1] == char) or (i < len(s)-1 and s[i+1] == char):
                    continue
                s[i] = char
                break
                
    # 将列表转换回字符串并返回
    return ''.join(s)

# 示例
s1 = "?zs"
s2 = "ubv?w"
s3 = "j?qg??b"
s4 = "??yw?ipkj?"

print("原始字符串:", s1, "-> 修改后字符串:", modifyString(s1))
print("原始字符串:", s2, "-> 修改后字符串:", modifyString(s2))
print("原始字符串:", s3, "-> 修改后字符串:", modifyString(s3))
print("原始字符串:", s4, "-> 修改后字符串:", modifyString(s4))

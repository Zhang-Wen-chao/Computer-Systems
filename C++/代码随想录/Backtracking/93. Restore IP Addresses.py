def restoreIpAddresses(s):
    def backtrack(start, path):
        # 如果找到了4个部分，并且遍历完了字符串，则添加到结果中
        if len(path) == 4 and start == len(s):
            result.append(".".join(path))
            return
        # 如果超过4个部分或者字符串已经用完，但是没有找到4个部分，则返回
        if len(path) > 4 or start == len(s):
            return

        for length in range(1, 4):  # 尝试长度为1, 2, 3的每个部分
            if start + length <= len(s):  # 确保不会超出字符串的长度
                part = s[start:start + length]
                # 检查这部分是否有效（不以0开头，除非是0本身；并且小于等于255）
                if (len(part) == 1 or (part[0] != '0' and int(part) <= 255)):
                    backtrack(start + length, path + [part])

    result = []
    backtrack(0, [])
    return result

# 测试用例
s = "25525511135"
print(restoreIpAddresses(s))

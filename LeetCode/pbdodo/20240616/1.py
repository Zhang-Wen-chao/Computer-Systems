# 多多君是一个完美主义者，他很喜欢用完整的排列序列。
# 一个完整的排列序列定义为一个长度为n的序列，包含从1到n所有数字，且每个数字只出现一次，序列中数字的排列序列随意。
# 现在多多君有一个长度为m的序列，序列中的数字不会有重复，他记得其中可能缺少了一部分数字，并且这些缺少的数字和为s。
# 现在他想知道通过补全这些数字，能否让这个序列变为一个完整的序列。
# 如果能，就输出yes，不能就输出no。 
# 输入： 第一行为数字t，表示当前样例中序列数对于每个序列，输入包含两行。
# 第一行包含两个整数，m,表示序列长度，缺少的一部分数字和为s.
# 第二行包含m个整数，表示原来序列中的数字。
def can_complete_sequences(t, test_cases):
    results = []
    for case in test_cases:
        m, s = case[0]
        sequence = case[1]
        
        # 已知序列的总和
        known_sum = sum(sequence)
        
        # 最大数字
        max_num = max(sequence)
        
        # 计算1到max_num的总和
        total_sum = max_num * (max_num + 1) // 2
        
        # 需要补充的数字总和
        missing_sum = total_sum - known_sum
        
        # 计算需要的数字个数
        n = max_num
        while missing_sum < s:
            n += 1
            missing_sum += n
        
        # 检查是否可以满足条件
        if missing_sum == s:
            results.append("yes")
        else:
            results.append("no")
    
    return results

# 输入处理
def main():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    index = 0
    t = int(data[index])
    index += 1
    test_cases = []
    
    for _ in range(t):
        m = int(data[index])
        s = int(data[index + 1])
        index += 2
        sequence = list(map(int, data[index:index + m]))
        index += m
        test_cases.append(((m, s), sequence))
    
    results = can_complete_sequences(t, test_cases)
    for result in results:
        print(result)

# 调用主函数
if __name__ == "__main__":
    main()

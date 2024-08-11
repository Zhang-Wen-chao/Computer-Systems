# 在一个简单的哈希表实现中，对于给定哈西函数fx=x%n，有一个长度为n的数组用于存储x值。
# 当需要向哈希表插入一个值x时，从数组下标fx开始，向右循环移动，找到第一个未存储过数字的位置，写入x,若哈希表已满或者x已经存在于表中，则不再插入x。
# 给定n个整数，表示哈希表数组中存储的元素，-1表示当前位置未写入数据。
# 请判断是否存在一个合法的插入序列，使得哈希表中存储的状态与输入完全一致。 
# 输入：第一行为一个正整数T，表示有T组数据，每组数据的第一行为一个正整数n,第二行为n个整数a1,a2,,,an,含义如题。 
# 输出：对于每组数据，若存在满足条件的输入序列，输出yes,否则输出no，输出全为小写字母。
def can_form_hash_table(n, array):
    hash_table = [-1] * n
    
    for index, value in enumerate(array):
        if value == -1:
            continue
        
        # Calculate the hash index
        hash_index = value % n
        
        # Try to insert the value into the hash table
        found = False
        for i in range(n):
            pos = (hash_index + i) % n
            if hash_table[pos] == -1:
                if i == index:
                    hash_table[pos] = value
                    found = True
                    break
            elif hash_table[pos] == value:
                found = True
                break
        
        if not found:
            return "no"
    
    return "yes"

def process_test_cases(test_cases):
    results = []
    for case in test_cases:
        n, array = case
        results.append(can_form_hash_table(n, array))
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
        n = int(data[index])
        index += 1
        array = list(map(int, data[index:index + n]))
        index += n
        test_cases.append((n, array))
    
    results = process_test_cases(test_cases)
    for result in results:
        print(result)

# 调用主函数
if __name__ == "__main__":
    main()

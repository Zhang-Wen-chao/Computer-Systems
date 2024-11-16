q = int(input())  # 读取询问次数
queries = [tuple(map(int, input().split())) for _ in range(q)]  # 读取所有询问

deleted = {}  # 用来记录某个数字是否已经删除，并存储下一个未被删除的数字
last_deleted = 0  # 存储最后删除的数字

def find_next_free(num):
    # 如果 num 已经被删除并跳跃过，则找到下一个未被删除的数字
    if num in deleted:
        deleted[num] = find_next_free(deleted[num])
        return deleted[num]
    return num

for x, y in queries:
    current = find_next_free(x)
    
    for _ in range(y):
        deleted[current] = current + 1  # 标记删除，并存储下一个未删除的数字
        last_deleted = current
        current = find_next_free(current + 1)
    
    print(last_deleted)

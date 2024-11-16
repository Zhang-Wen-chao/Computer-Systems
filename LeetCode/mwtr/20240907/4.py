q = int(input())  # 读取询问次数
queries = [tuple(map(int, input().split())) for _ in range(q)]  # 读取所有询问

deleted = set()  # 存储已经删除的数字
last_deleted = 0  # 存储最后删除的数字

for x, y in queries:
    current = x
    count = 0
    
    while count < y:
        # 找到第一个没有被删除的数
        while current in deleted:
            current += 1
        # 进行删除
        deleted.add(current)
        last_deleted = current
        current += 1
        count += 1
    
    print(last_deleted)

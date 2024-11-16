from collections import defaultdict, deque

def find_path(tree, start, end):
    queue = deque([(start, [])])
    visited = set()
    while queue:
        node, path = queue.popleft()
        if node in visited:
            continue
        visited.add(node)
        path = path + [node]
        if node == end:
            return path
        for neighbor in tree[node]:
            if neighbor not in visited:
                queue.append((neighbor, path))
    return []

def max_mex_in_tree(n, a, edges):
    tree = defaultdict(list)
    for u, v in edges:
        tree[u].append(v)
        tree[v].append(u)
    
    max_mex = 0
    for u in range(1, n + 1):
        for v in range(u + 1, n + 1):
            path = find_path(tree, u, v)
            if not path:
                continue
            
            path_values = sorted(a[node - 1] for node in path)
            mex = 0
            for value in path_values:
                if value == mex:
                    mex += 1
                else:
                    break
            max_mex = max(max_mex, mex)
    
    return max_mex

def process_input_for_max_mex_in_tree():
    # 读取输入
    n = int(input().strip())
    a = list(map(int, input().strip().split()))
    edges = []
    for _ in range(n - 1):
        u, v = map(int, input().strip().split())
        edges.append((u, v))
    
    # 计算最大 MEX
    result = max_mex_in_tree(n, a, edges)
    print(result)

# 调用函数处理输入
process_input_for_max_mex_in_tree()

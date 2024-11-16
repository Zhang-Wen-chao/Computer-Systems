import sys
from collections import defaultdict
import sys
sys.setrecursionlimit(1 << 25)

def main():
    import sys
    from collections import defaultdict

    input = sys.stdin

    try:
        # 读取第一个整数 n
        n_line = input.readline()
        if not n_line:
            print(-1)
            return
        n = int(n_line.strip())
    except:
        print(-1)
        return

    if n == 1:
        # 对于只有一个节点的情况，没有邻居，无法满足要求
        print(-1)
        return

    adj = defaultdict(list)
    # 读取接下来的 n-1 条边
    for _ in range(n-1):
        line = input.readline()
        if not line:
            # 如果边的数量不足 n-1 条，输出 -1
            print(-1)
            return
        try:
            u, v = map(int, line.strip().split())
            adj[u].append(v)
            adj[v].append(u)
        except:
            # 如果边的格式不正确，输出 -1
            print(-1)
            return

    # 检查节点数是否为偶数
    if n % 2 != 0:
        print(-1)
        return

    # 检查是否有节点拥有两个或更多的叶子子节点
    invalid = False
    for u in range(1, n+1):
        leaf_children = 0
        for v in adj[u]:
            if len(adj[v]) == 1:
                leaf_children += 1
                if leaf_children >= 2:
                    invalid = True
                    break
        if invalid:
            break
    if invalid:
        print(-1)
        return

    matched = [False] * (n + 1)
    pairs = []

    def dfs(u, parent):
        for v in adj[u]:
            if v != parent:
                dfs(v, u)
                if not matched[v] and not matched[u]:
                    matched[u] = matched[v] = True
                    pairs.append((u, v))

    dfs(1, -1)

    if not all(matched[1:]):
        print(-1)
        return

    # 对匹配的节点对进行排序以保证一致性
    pairs.sort()

    color = [''] * (n + 1)
    current_color = 'R'
    for u, v in pairs:
        color[u] = current_color
        color[v] = current_color
        # 交替颜色
        current_color = 'B' if current_color == 'R' else 'R'

    # 验证每个节点是否满足有且仅有一个相同颜色的邻居
    valid = True
    for u in range(1, n+1):
        cnt = 0
        for v in adj[u]:
            if color[v] == color[u]:
                cnt += 1
        if cnt != 1:
            valid = False
            break
    if not valid:
        print(-1)
        return

    # 构建输出字符串
    output = ''.join(color[1:])
    print(output)

if __name__ == "__main__":
    main()

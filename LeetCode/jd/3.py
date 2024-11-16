def main():
    import sys
    sys.setrecursionlimit(1 << 25)

    n = int(sys.stdin.readline())
    colors = [0] + list(map(int, sys.stdin.readline().split()))
    adj = [[] for _ in range(n + 1)]

    for _ in range(n - 1):
        u, v = map(int, sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)

    max_xor = 0

    for root in range(1, n + 1):
        color_counts = {}
        nodes_colors = []

        def dfs(u, parent):
            color_u = colors[u]
            color_counts[color_u] = color_counts.get(color_u, 0) + 1
            nodes_colors.append((u, color_u))
            for v in adj[u]:
                if v != parent:
                    dfs(v, u)

        dfs(root, 0)

        if not nodes_colors:
            continue  # If no nodes collected, skip

        max_freq = max(color_counts.values())
        # Identify colors to remove
        colors_to_remove = set(color for color, freq in color_counts.items() if freq == max_freq)

        # Compute XOR of remaining colors
        xor_sum = 0
        for node, color in nodes_colors:
            if color not in colors_to_remove:
                xor_sum ^= color

        if xor_sum > max_xor:
            max_xor = xor_sum

    print(max_xor)

if __name__ == "__main__":
    main()

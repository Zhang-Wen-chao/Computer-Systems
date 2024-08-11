# 小美的彩带是由一条长度为n的彩带一直无限循环得到的，彩带的每一个位置都有一个颜色，用ai表示。因此当i>n时，a_i=a_(i-n)。
# 小美每次会从左往右或者从右往左剪一段长度为x的彩带，她想知道她每次剪下来的彩带有多少种颜色。
# 输入：
# 6 3
# 1 1 4 5 1 4
# L 2
# L 3
# R 12
# 输出
# 1
# 3
# 3
# 说明：输入第一行是两个整数，n,q(1<=n, q<=2*10**5) 代表彩带长度、剪彩带次数。
# 第二行输入n个整数a1,a2,...an(1<=ai<=10**9)代表彩带每一个位置的颜色。
# 此后q行，每行输入一个字符c和一个整数x（1<=x<=10**9;c in 'L', 'R') 代表裁剪方向和裁剪长度，其实'L'说明从左往右剪，'R'说明从右往走剪。
# 对于每一次裁剪彩带，在一行上输出一个整数代表颜色数量。
# 第一次裁剪彩带，剪下来的是[1,1],有[1]这1种颜色；
# 第二次裁剪彩带，剪下来的是[4,5,1],有[4,5,1]这3种颜色；
# 第三次裁剪彩带，剪下来的是[1,1,4,5,1,4,1,1,4,5,1,4],有[1,4,5]这3种颜色。
class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.tree = [0] * (n + 1)

    def lowbit(self, x):
        return x & -x

    def update(self, index, value):
        while index <= self.n:
            self.tree[index] += value
            index += self.lowbit(index)

    def query(self, index):
        sum = 0
        while index > 0:
            sum += self.tree[index]
            index -= self.lowbit(index)
        return sum

# 处理函数
def process_ribbon(n, q, colors, queries_input):
    # 延伸彩带，处理循环
    colors += colors[1:n + 1]

    queries = []
    currentL = 0
    currentR = 2 * n

    for i in range(1, q + 1):
        direction, x = queries_input[i - 1]
        if direction == 'L':
            currentL %= n
            if x >= n:
                l, r = 0, n
                currentL += (x % n)
            else:
                l = currentL
                r = currentL + (x % n)
                currentL += (x % n)
        else:  # direction == 'R'
            currentR = (currentR % n) + n
            if x >= n:
                l, r = 0, n
                currentR = currentR - (x % n) + n
            else:
                l = currentR - x
                r = currentR
                currentR -= x
        
        queries.append((l, r, i))

    # 按照 r 的顺序排序查询
    queries.sort(key=lambda x: x[1])

    fenwick_tree = FenwickTree(2 * n)
    last_occurrence = [0] * (max(colors) + 1)
    result = [0] * (q + 1)

    next_pos = 1
    for l, r, index in queries:
        for j in range(next_pos, r + 1):
            if last_occurrence[colors[j]]:
                fenwick_tree.update(last_occurrence[colors[j]], -1)
            fenwick_tree.update(j, 1)
            last_occurrence[colors[j]] = j
        next_pos = r + 1
        result[index] = fenwick_tree.query(r) - fenwick_tree.query(l)

    # 返回结果
    return result

# 示例输入
n, q = 6, 3
colors = [0, 1, 1, 4, 5, 1, 4]  # 注意：index 0 不使用
queries_input = [
    ('L', 2),
    ('L', 3),
    ('R', 12)
]

# 键盘输入
# n, q = map(int, input().split())
# colors = [0] + list(map(int, input().split()))  # 注意：index 0 不使用
# queries_input = [tuple(input().split()) for _ in range(q)]
# queries_input = [(c, int(x)) for c, x in queries_input]

# 调用函数并输出结果
result = process_ribbon(n, q, colors, queries_input)
for i in range(1, q + 1):
    print(result[i])

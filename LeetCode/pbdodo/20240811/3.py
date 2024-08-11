# 第三题像找最长重复子串，可以修改一次。如下：
# 多多喜欢玫瑰和牡丹，多多在他的花坛种了n盆花，每盆花要么是玫瑰要么是牡丹，从左往右依次摆放，编号从1到n。
# 定义花坛的观赏度为玫瑰与牡丹的盆数之差的绝对值，现在定义一种操作，
# 选取一段连续的区间[l,r]，将编号l到编号r的花盆中的玫瑰替换成牡丹，或将牡丹替换成玫瑰。
# 多多不关心观赏度的高低，而是关心观赏度的种花坛一共有多少类，问经过至多一次这样的操作，花坛一共有多少种不同的观赏度。
# 输入共两行：第一行表示n盆花，第二行n个数字，0表示玫瑰，1表示牡丹。
# Input 1:
# 2
# 0 1
# Output 1: 2

# Input 2: 
# 4 
# 0 1 1 0
# Output 2: 2
def count_distinct_views(n, flowers):
    # 计算原始的观赏度
    original_view = abs(flowers.count(0) - flowers.count(1))
    distinct_views = {original_view}

    # 遍历所有可能的翻转区间
    for i in range(n):
        for j in range(i, n):
            # 计算区间 [i, j] 中0的个数（翻转后这些0会变成1）
            num_zeros = flowers[i:j+1].count(0)
            
            # 翻转后的观赏度：玫瑰的数量减少，牡丹的数量增加
            new_view = abs((flowers.count(0) - num_zeros) - (flowers.count(1) + num_zeros))
            distinct_views.add(new_view)
    
    return len(distinct_views)

# 示例测试
n1 = 2
flowers1 = [0, 1]
print(count_distinct_views(n1, flowers1))  # 输出 2

n2 = 4
flowers2 = [0, 1, 1, 0]
print(count_distinct_views(n2, flowers2))  # 输出 2


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
# 不操作，观赏度为0，
# 操作区间［1,1］，观赏度为2，操作区间［2,2］，观赏度为2，操作区间［1,2］，观赏度为0，共有2种不同的观赏度。

# Input 2: 
# 4 
# 0 1 1 0
# Output 2: 2

n = int(input())
flowers = list(map(int, input().split()))

# 将花的编码转为1表示牡丹，-1表示玫瑰
flowers = [1 if flower == 1 else -1 for flower in flowers]

min_prefix_sum, max_prefix_sum = 0, 0
min_result, max_result = 0, 0
current_prefix_sum = 0

for i, flower in enumerate(flowers):
    current_prefix_sum += flower
    
    # 更新最小结果和最大结果
    min_result = min(min_result, current_prefix_sum - max_prefix_sum)
    max_result = max(max_result, current_prefix_sum - min_prefix_sum)
    
    # 更新最小和最大前缀和
    min_prefix_sum = min(min_prefix_sum, current_prefix_sum)
    max_prefix_sum = max(max_prefix_sum, current_prefix_sum)

# 计算经过操作后观赏度的最小和最大可能值
min_observation, max_observation = current_prefix_sum - 2 * max_result, current_prefix_sum - 2 * min_result

# 计算结果
if min_observation * max_observation < 0:
    print(max_observation // 2 + 1)
else:
    print((max_observation - min_observation) // 2 + 1)

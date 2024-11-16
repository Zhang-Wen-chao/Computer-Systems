def min_cost_to_move_bottles(a, b, c, d, bottles):
    total_cost = 0
    current_x, current_y = a, b
    
    for xi, yi in bottles:
        # 移动到瓶子的位置
        move_to_bottle = abs(current_x - xi) + abs(current_y - yi)
        # 再将瓶子移动到目标位置
        move_to_target = abs(xi - c) + abs(yi - d)
        # 总代价
        total_cost += move_to_bottle + move_to_target
        # 更新当前坐标为目标位置
        current_x, current_y = c, d
    
    return total_cost

def process_input():
    # 读取输入
    a, b, c, d = map(int, input().split())
    n = int(input())
    bottles = []
    for _ in range(n):
        xi, yi = map(int, input().split())
        bottles.append((xi, yi))
    
    # 计算最小代价
    result = min_cost_to_move_bottles(a, b, c, d, bottles)
    print(result)

# 示例调用
if __name__ == "__main__":
    process_input()

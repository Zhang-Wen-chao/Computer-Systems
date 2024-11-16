def max_product_after_operations(a, b, c, k):  
    mod = 10**9 + 7  
    nums = [a, b, c]  
    
    # 持续操作直到k为0
    for _ in range(k):
        # 每次找到最小的数字并增加
        nums.sort()  # 排序以确保nums[0]为最小值
        nums[0] += 1
    
    # 计算乘积并取模
    result = (nums[0] * nums[1] * nums[2]) % mod
    return result
  
def process_input_for_max_product():  
    # 读取输入  
    a, b, c, k = map(int, input().split())  
    
    # 计算最大乘积  
    result = max_product_after_operations(a, b, c, k)  
    print(result)  
  
if __name__ == "__main__":  
    process_input_for_max_product()

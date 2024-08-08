def mySqrt(x: int) -> int:
    if x == 0:
        return 0
    left, right = 1, x
    while left <= right:
        mid = left + (right - left) // 2
        if mid * mid == x:
            return mid
        elif mid * mid < x:
            left = mid + 1
        else:
            right = mid - 1
    return right

# 示例
x = 8
print(f"The integer square root of {x} is {mySqrt(x)}")  # 输出：The integer square root of 8 is 2

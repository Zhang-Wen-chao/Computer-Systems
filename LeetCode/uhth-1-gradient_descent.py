import numpy as np

# 定义目标函数
def f(x):
    return 0.05 * x**2 - 5 + np.sin(x)

# 面试官刚开始给的是单调函数，改成了sin(x)就是为了让我不能再用梯度下降法，因为sin(x)是个震荡函数。最终诱导我说出了有限范围内可以穷举。

# 定义目标函数的导数
def df(x):
    return 0.1 * x + np.cos(x)

# 梯度下降法
def gradient_descent(starting_point, learning_rate, tolerance, max_iterations):
    x = starting_point
    for _ in range(max_iterations):
        gradient = df(x)
        new_x = x - learning_rate * gradient
        if abs(new_x - x) < tolerance:
            break
        x = new_x
    return x

# 设置初始点、学习率、容差和最大迭代次数
starting_point = 5.0
learning_rate = 0.01
tolerance = 1e-6
max_iterations = 10000

# 执行梯度下降法
min_x = gradient_descent(starting_point, learning_rate, tolerance, max_iterations)
min_value = f(min_x)

print(f"Minimum value of the function: {min_value}")
print(f"At point: {min_x}")
def largestRectangleArea(heights):
    stack = []
    max_area = 0
    heights.append(0)

    for i in range(len(heights)):
        while stack and heights[i] < heights[stack[-1]]:
            h = heights[stack.pop()]
            w = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, h * w)
        stack.append(i)

    return max_area

# 测试用例
print(largestRectangleArea([2,1,5,6,2,3]))  # 应输出 10

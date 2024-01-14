def nextGreaterElement(nums1, nums2):
    stack = []
    greater = {}
    
    for num in nums2:
        while stack and stack[-1] < num:
            greater[stack.pop()] = num
        stack.append(num)

    return [greater.get(num, -1) for num in nums1]

# 测试用例
print(nextGreaterElement([4,1,2], [1,3,4,2]))  # 应输出 [-1,3,-1]
print(nextGreaterElement([2,4], [1,2,3,4]))    # 应输出 [3,-1]

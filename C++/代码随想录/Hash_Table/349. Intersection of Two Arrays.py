def intersection(nums1, nums2):
    set1 = set(nums1)
    set2 = set(nums2)
    return list(set1 & set2)

# 测试用例
print(intersection([1, 2, 2, 1], [2, 2]))  # 应该输出 [2]
print(intersection([4, 9, 5], [9, 4, 9, 8, 4]))  # 应该输出 [9, 4]

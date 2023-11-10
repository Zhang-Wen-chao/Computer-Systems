def two_sum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    hash_table = {}
    for i, num in enumerate(nums):
        if target - num in hash_table:
            return [hash_table[target - num], i]
        hash_table[num] = i
    return []

# Test cases
if __name__ == "__main__":
    # Test case 1
    nums1 = [2, 7, 11, 15]
    target1 = 9
    print(f"Test case 1: {two_sum(nums1, target1)}")  # Output: [0, 1]

    # Test case 2
    nums2 = [3, 2, 4]
    target2 = 6
    print(f"Test case 2: {two_sum(nums2, target2)}")  # Output: [1, 2]

    # Test case 3
    nums3 = [3, 3]
    target3 = 6
    print(f"Test case 3: {two_sum(nums3, target3)}")  # Output: [0, 1]
    
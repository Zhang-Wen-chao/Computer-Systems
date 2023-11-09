def search(nums, target):
    left, right = 0, len(nums) - 1
    
    while left <= right:
        mid = left + (right - left) // 2
        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    
    return -1

# Test cases
print(search([-1,0,3,5,9,12], 9))  # Output: 4
print(search([-1,0,3,5,9,12], 2))  # Output: -1
print(search([5], 5))              # Output: 0

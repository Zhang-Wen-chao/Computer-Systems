def removeElement(nums, val):
    k = 0  # Pointer for the next position to place the non-val element
    for i in range(len(nums)):
        if nums[i] != val:
            nums[k] = nums[i]
            k += 1
    return k

# Test cases
nums1 = [3, 2, 2, 3]
val1 = 3
new_length1 = removeElement(nums1, val1)
print(new_length1, nums1[:new_length1])  # Output: 2 [2, 2]

nums2 = [0,1,2,2,3,0,4,2]
val2 = 2
new_length2 = removeElement(nums2, val2)
print(new_length2, nums2[:new_length2])  # Output: 5 [0, 1, 3, 0, 4]

def sortedSquares(nums):
    return sorted(x*x for x in nums)

# Test cases
print(sortedSquares([-4,-1,0,3,10]))  # Output: [0,1,9,16,100]
print(sortedSquares([-7,-3,2,3,11]))  # Output: [4,9,9,49,121]

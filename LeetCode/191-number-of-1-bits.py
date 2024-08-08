class Solution:
    def hammingWeight(self, n: int) -> int:
        count = 0
        while n:
            count += n & 1
            n >>= 1
        return count

# Example usage:
solution = Solution()
print(solution.hammingWeight(11))  # Output: 3, because 11 in binary is 1011 and it has three '1' bits.
print(solution.hammingWeight(128))  # Output: 1, because 128 in binary is 10000000 and it has one '1' bit.
print(solution.hammingWeight(2147483645))  # Output: 31, because 4294967293 in binary is
# 59. Spiral Matrix II
# https://leetcode.com/problems/spiral-matrix-ii/
class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        maxNum = n * n
        curNum = 1
        matrix = [[0] * n for _ in range(n)]
        row, column = 0, 0
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        directionIndex = 0
        while curNum <= maxNum:
            matrix[row][column] = curNum
            curNum += 1
            nextRow = row + directions[directionIndex][0]
            nextColumn = column + directions[directionIndex][1]
            if (
                nextRow < 0
                or nextRow >= n
                or nextColumn < 0
                or nextColumn >= n
                or matrix[nextRow][nextColumn] != 0
            ):
                directionIndex = (directionIndex + 1) % 4
            row += directions[directionIndex][0]
            column += directions[directionIndex][1]
        return matrix

def main():
    sol = Solution()
    n = 4
    ans = sol.generateMatrix(n)
    for row in ans:
        print(*row)

if __name__ == "__main__":
    main()
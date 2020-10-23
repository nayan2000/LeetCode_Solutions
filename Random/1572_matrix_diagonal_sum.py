class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        if not mat:
            return 0
        rows = len(mat)
        sum = 0
        for i in range(rows):
            sum+=(mat[i][i]+mat[i][rows-i-1])
        if rows%2:
            sum-=mat[rows//2][rows//2]
        return sum
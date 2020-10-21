class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if not matrix or not len(matrix[0]):
            return False
        n = len(matrix)
        low = 0
        high = n-1
        while low <= high:
            mid = (low+high)//2
            if target >= matrix[mid][0] and target <= matrix[mid][-1]:
                try:
                    matrix[mid].index(target)
                    return True
                except:
                    return False
            elif target < matrix[mid][-1]:
                high = mid-1
            else:
                low = mid+1
        return False

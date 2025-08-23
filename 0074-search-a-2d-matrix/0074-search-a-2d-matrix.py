class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        #seach for column first
        n = len(matrix)
        m = len(matrix[0])
        low = 0
        high = n - 1
        mid = (low + high) // 2
        row = -1
        while low <= high:
            mid = (low + high) // 2
            if target > matrix[mid][m - 1]:
                low = mid + 1
            else:
                row = mid
                high = mid - 1
        if row == -1:
            return False
        print(row)
        low = 0
        high = m - 1
        while low <= high:
            mid = (low + high) // 2
            if target == matrix[row][mid]:
                return True
            if target > matrix[row][mid]:
                low = mid + 1
            else:
                high = mid - 1
        return False

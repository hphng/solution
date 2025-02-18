class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) -1
        while left <= right:
            m = (right+left)//2
            if nums[m] == target:
                return m
            if nums[left] <= nums[m]:
                if nums[left] <= target < nums[m]:
                    right = m - 1
                else:
                    left = m + 1
            else:
                if nums[m] < target <= nums[right]:
                    left = m + 1
                else:
                    right = m - 1
        return -1
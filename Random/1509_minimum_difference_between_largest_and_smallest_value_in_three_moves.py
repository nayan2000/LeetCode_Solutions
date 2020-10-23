# O(nLogn) solution
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums)<5:
            return 0
        nums.sort()
        return min(nums[-4]-nums[0], \
                   nums[-3]-nums[1], \
                   nums[-2] - nums[2], \
                   nums[-1] - nums[3])

#O(n) solution using heapq
class Solution:
    def minDifference(self, nums: List[int]) -> int:
        if len(nums)<5:
            return 0
        max_4 = heapq.nlargest(4, nums)
        min_4 = heapq.nsmallest(4, nums)
        return min([max_4[i]-min_4[3-i] for i in range(4)])
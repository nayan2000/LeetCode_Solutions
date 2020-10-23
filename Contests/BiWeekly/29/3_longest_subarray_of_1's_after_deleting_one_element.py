def cnt_ones_before(arr):
    res=0
    for i in range(len(arr)-1,-1,-1):
        if arr[i]==0:
            return res
        else:
            res+=1
    return len(arr)
def cnt_ones_after(arr):
    res=0
    for i in arr:
        if not i:
            return res
        else:
            res+=1
    return len(arr)
    

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        if nums==[1]*len(nums):
            return len(nums)-1
        res=0
        for i in range(0,len(nums)):
            if not nums[i]:
                curr = cnt_ones_before(nums[:i])+cnt_ones_after(nums[i+1:])
                res = max(curr, res)
        return res
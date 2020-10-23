'''
Initial Naive Approach 
TC-O(N^2)
SC-O(N)
'''
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if not nums or len(nums)<3:
            return False
        minStore = [0]*len(nums)
        minStore[0] = nums[0]
        n = len(nums)
        for i in range(1,n):
            minStore[i] = min(nums[i], minStore[i-1])
        for j in range(n-2,-1,-1):
            if minStore[j]<nums[j]:
                for i in range(j+1, n):
                    if nums[i]>minStore[j] and nums[i]<nums[j]:
                        return True
        return False

'''
Optimised approach
TC-O(N)
SC-O(N)
'''
class Solution:
    def find132pattern(self, nums: List[int]) -> bool:
        if not nums or len(nums)<3:
            return False
        minStore = [0]*len(nums)
        minStore[0] = nums[0]
        n = len(nums)
        for i in range(1,n):
            minStore[i] = min(nums[i], minStore[i-1])
        stack=[]
        for j in range(n-1,-1,-1):
            if nums[j]>minStore[j]:
                while stack and stack[-1]<=minStore[j]:
                    stack.pop()
                if stack and stack[-1]<nums[j]:
                    return True
                stack.append(nums[j])
        return False
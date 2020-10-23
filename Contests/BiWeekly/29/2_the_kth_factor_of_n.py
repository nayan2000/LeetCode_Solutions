class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        if k==1:
            return 1
        factors = set([1])
        count=1
        for i in range(2,n+1):
            if n%i==0:
                count+=1
                factors.add(i)
            if count==k:
                return i
        return -1
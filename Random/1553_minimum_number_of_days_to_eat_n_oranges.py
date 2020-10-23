store = {0:0,1:1}
def dp(n):
    if n not in store:
        store[n]=1+min(n%2+dp(n//2),n%3+dp(n//3))
    return store[n]

class Solution:
    def minDays(self, n: int) -> int:
        return dp(n)
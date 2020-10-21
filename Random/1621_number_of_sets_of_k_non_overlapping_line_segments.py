from math import comb
mod=10**9+7
class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        return comb(n+k-1, n-k-1)%mod

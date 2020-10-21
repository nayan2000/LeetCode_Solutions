from collections import defaultdict


class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        d = defaultdict(int)
        for i in range(len(s)-k+1):
            d[s[i:i+k]] += 1
        if len(d) != 2**k:
            return False
        return True

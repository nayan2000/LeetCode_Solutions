from collections import defaultdict

class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        d = defaultdict(int)
        for i in range(len(s)):
            d[s[i:i+10]] += 1
        return [x for x, v in d.items() if v > 1]

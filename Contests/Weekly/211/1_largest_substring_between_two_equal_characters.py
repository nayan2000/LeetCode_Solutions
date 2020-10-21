from collections import defaultdict

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        d = defaultdict(list)
        for i in range(len(s)):
            d[s[i]].append(i)
        e = sorted(d, key=lambda x: -len(d[x]))
        if len(d[e[0]]) < 2:
            return -1
        max1 = 0
        for i in e:
            max1 = max(max1, d[i][-1]-d[i][0]-1)
        return max1
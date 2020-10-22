from collections import Counter
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = Counter(words)
        return sorted(list(c.keys()), key=lambda x:(-c[x],x))[:k]
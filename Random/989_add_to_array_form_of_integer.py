class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        return list(map(int, str(int(''.join(map(str, A)))+K)))
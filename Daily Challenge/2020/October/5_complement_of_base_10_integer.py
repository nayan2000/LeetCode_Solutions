class Solution:
    def bitwiseComplement(self, N: int) -> int:
        k = N
        if N < 2:
            return 1-N
        if N == 2:
            return 1
        num = 1
        while N:
            N >>= 1
            num <<= 1
        return num-1-k

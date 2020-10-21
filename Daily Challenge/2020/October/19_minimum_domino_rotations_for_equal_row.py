from collections import defaultdict

class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        mapA = defaultdict(int)
        mapB = defaultdict(int)
        for i in A:
            mapA[i] += 1
        for i in B:
            mapB[i] += 1
        if len(mapA) == 1 or len(mapB) == 1:
            return 0
        maxElA = max(mapA, key=mapA.get)
        maxA = mapA[maxElA]
        maxElB = max(mapB, key=mapB.get)
        maxB = mapB[maxElB]
        if maxA >= maxB:
            count = 0
            for i in range(len(A)):
                if A[i] != maxElA:
                    if B[i] == maxElA:
                        count += 1
                    else:
                        return -1
            return count
        else:
            count = 0
            for i in range(len(B)):
                if B[i] != maxElB:
                    if A[i] == maxElB:
                        count += 1
                    else:
                        return -1
            return count

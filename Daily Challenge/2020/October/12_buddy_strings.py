from collections import Counter

class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:
        if len(A) < 2 or len(B) < 2:
            return False
        a = Counter(A)
        b = Counter(B)
        if a != b:
            return False
        if len(a) == 1:
            return True
        replacable = []
        for i in range(len(A)):
            if A[i] != B[i]:
                replacable.append(i)
            if len(replacable) > 2:
                return False
        if len(replacable) == 1:
            return False
        if len(replacable) == 0:
            if a[max(a, key=a.get)] > 1:
                return True
        else:
            b = list(B)
            b[replacable[0]], b[replacable[1]] = b[replacable[1]], b[replacable[0]]
            if ''.join(b) == A:
                return True
        return False

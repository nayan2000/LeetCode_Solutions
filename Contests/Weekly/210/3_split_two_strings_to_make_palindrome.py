def isPalindrome(s):
    return s == s[::-1]


class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        if isPalindrome(a) or isPalindrome(b):
            return True
        l = len(a)
        i1 = 0
        while i1 <= l//2:
            if a[i1] != b[-i1-1]:
                break
            else:
                i1 += 1
        i2 = 0
        while i2 <= l//2:
            if b[i2] != a[-i2-1]:
                break
            else:
                i2 += 1
        i = max(i1, i2)
        if isPalindrome(a[i:l-i]):
            return True
        if isPalindrome(b[i:l-i]):
            return True
        return False

class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num<=0:
            return False
        s = bin(num)
        s=s[2:]
        if len(s)%2:
            if s[0]=='1':
                if s[1:]=='0'*(len(s)-1):
                    return True
                return False
            else:
                return False
        else:
            return False
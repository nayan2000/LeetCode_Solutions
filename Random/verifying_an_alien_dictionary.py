import string

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        #get string of lowercase characters 'abc...z'
        alpha = string.ascii_lowercase
        mapp = dict(zip(order, alpha))
        words[0] = ''.join(mapp.get(x) for x in words[0])
        for i in range(1, len(words)):
            words[i] = ''.join(mapp.get(x) for x in words[i])
            if words[i] < words[i-1]:
                return False
        return True

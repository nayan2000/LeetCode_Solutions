class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        lastPos = {}
        for i in range(len(s)):
            lastPos[s[i]] = i
        stack = []
        seen = set()
        for i in range(len(s)):
            if s[i] in seen:
                continue
            while stack and stack[-1] > s[i] and lastPos[stack[-1]] > i:
                p = stack.pop()
                seen.remove(p)
            stack.append(s[i])
            seen.add(s[i])
        return "".join(stack)

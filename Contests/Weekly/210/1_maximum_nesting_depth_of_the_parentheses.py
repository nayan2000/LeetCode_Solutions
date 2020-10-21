class Solution:
    def maxDepth(self, s: str) -> int:
        n = len(s)
        if n < 2:
            return 0
        max_depth = 0
        curr_depth = 0
        for i in range(n):
            if s[i] == '(':
                curr_depth += 1
                max_depth = max(max_depth, curr_depth)
            elif s[i] == ')':
                curr_depth -= 1
            else:
                pass
        if curr_depth > 0:
            return 0

        return max_depth

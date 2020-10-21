class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0
        a = sorted(intervals, key=lambda x: x[0])
        to_delete = []
        for i in range(len(a)-1):
            if a[i][0] == a[i+1][0] and a[i][1] <= a[i+1][1]:
                to_delete.append(i)
        for i in to_delete:
            del a[i]
        b = [a[i][1] for i in range(len(a))]
        lMax = [b[0]]*len(b)
        res = []
        for i in range(1, len(b)):
            lMax[i] = max(b[i], lMax[i-1])
            if b[i] <= lMax[i-1]:
                res.append(i)
        return len(a)-len(res)

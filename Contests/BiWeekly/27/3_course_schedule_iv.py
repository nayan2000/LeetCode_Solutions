from collections import defaultdict


class Solution:
    def checkIfPrerequisite(self, n: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        if not prerequisites:
            return [False]*len(queries)
        mapp = defaultdict(list)
        for p in prerequisites:
            mapp[p[1]].append(p[0])
        #as the map is changing in the loop
        c = list(mapp.keys()).copy()
        for k in c:
            l = set(mapp[k])
            for i in mapp[k]:
                l = l.union(set(mapp[i]))
            mapp[k] = list(l)
        #call this twice so as to update the map completely
        for k in c:
            l = set(mapp[k])
            for i in mapp[k]:
                l = l.union(set(mapp[i]))
            mapp[k] = list(l)
        res = []
        for i in queries:
            if i[0] in mapp[i[1]]:
                res.append(True)
            else:
                res.append(False)
        return res

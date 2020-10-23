#DFS Solution
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        if not graph:
            return []
        res = []
        source = 0
        target = len(graph)-1
        def DfsUtil(src, curr):
            if src==target:
                res.append(curr+[target])
                return
            else:
                new = curr+[src]
                for n in graph[src]:
                    DfsUtil(n,new)
                return
            
        current = [source]
        for node in graph[source]:
            DfsUtil(node,current)
        return res
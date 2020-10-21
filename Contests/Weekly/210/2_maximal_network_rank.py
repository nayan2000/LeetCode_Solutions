from collections import defaultdict

class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        '''
        
            [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
        
        '''
        if n < 2:
            return 0
        if n == 2:
            if len(roads) > 0:
                return 1
            else:
                return 0
        m = defaultdict(list)
        for road in roads:
            m[road[0]].append(road[1])
            m[road[1]].append(road[0])
        max_list = sorted(m, key=lambda x: len(m[x]), reverse=True)
        print(max_list)
        max_rank = 0
        for i in range(len(max_list)):
            for j in range(i+1, len(max_list)):
                g = len(m[max_list[i]])+len(m[max_list[j]])
                if max_list[i] in m[max_list[j]]:
                    max_rank = max(max_rank, g-1)
                else:
                    max_rank = max(max_rank, g)
        return max_rank

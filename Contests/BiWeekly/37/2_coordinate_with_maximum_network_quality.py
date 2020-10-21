def getDist(x1, y1, x2, y2):
    return ((y1-y2)**2+(x1-x2)**2)**0.5


def getMin(x1, x2):
    if x1[0] > x2[0]:
        return 1
    elif x1[0] < x2[0]:
        return 0
    else:
        if x1[1] < x2[1]:
            return 0
        elif x1[1] > x2[1]:
            return 1
        else:
            return 0

class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        towers = sorted(towers, key=lambda x: -x[2])
        max_pow = 0
        max_index = 0
        for i in range(len(towers)):
            tower = towers[i]
            curr_pow = 0
            for j in towers:
                d = getDist(j[0], j[1], tower[0], tower[1])
                if d <= radius:
                    curr_pow += (j[2]/(1+d))//1
                else:
                    continue
            if curr_pow == max_pow:
                c = getMin(towers[max_index][:2], tower[:2])
                if c:
                    max_index = i
            elif curr_pow > max_pow:
                max_pow = max(curr_pow, max_pow)
                max_index = i
        return towers[max_index][:2]

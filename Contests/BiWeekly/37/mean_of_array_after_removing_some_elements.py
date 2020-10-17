class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        m1 = int(0.05*len(arr))
        orig_sum = sum(arr)
        to_remove = sum(arr[:m1])+sum(arr[-m1:])
        new_mean = (orig_sum - to_remove)/(len(arr)-2*m1)
        return new_mean
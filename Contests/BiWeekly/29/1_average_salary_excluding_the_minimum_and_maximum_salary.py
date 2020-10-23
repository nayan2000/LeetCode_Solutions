# One-Liner
class Solution:
    def average(self, salary: List[int]) -> float:
        return (sum(salary)-min(salary)-max(salary))/(len(salary)-2)

# SinglePass
class Solution:
    def average(self, salary: List[int]) -> float:
        '''
            The next 2 lines basically are for optimisation
            In python, local processing is faster
            So for functions which will be used repeatedly, its always good to
            assign them as a variable and use that.
        '''
        max1 = max
        min1 = min
        n = len(salary)
        max_el = salary[0]
        min_el = salary[0]
        sum_el= 0
        for el in salary:
            max_el = max1(max_el, el)
            min_el = min1(min_el, el)
            sum_el += el
        return (sum_el-max_el-min_el)/(n-2)
'''
    This map of months vs MonthNumber is kept global as it would be accessed in every testcase.
    Also, zfill is a format function fills zeroes to make the length as argument
'''
def zfill_implement(string, n):
    return ''.join(('0'*(n-len(string)),string))

months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
l = dict(zip(months, [str(x).zfill(2) for x in range(1,13)]))
class Solution:
    def reformatDate(self, date: str) -> str:
        d,m,y = date.split()
        return '-'.join([y,l[m], d[:-2].zfill(2)])
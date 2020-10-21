bool compare(const vector<int> &a, const vector<int> &b){
    if(a[0] == b[0]) return a[1] > b[1];
    return a[0] < b[0];
}
class Solution {
public:
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<int> interval = intervals[0];
        int count = 1;
        int i = 1;
        while(i < intervals.size()){
            while(i < intervals.size() && intervals[i][0] >= interval[0] && intervals[i][1] <= interval[1])
                i++;
            if(i == intervals.size()) break;
            count++;
            interval = intervals[i];
            i++;
        }
        return count;
    }
};
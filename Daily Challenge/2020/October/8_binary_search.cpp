class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        int mid = -1;
        //P: nums[x] > target
        //FFFFFTTTTT
        //Find last F
        while(lo < hi){
            mid = lo + (hi - lo + 1)/2;
            if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid;
        }
        //sanity check
        if(nums[lo] == target)
            return lo;
        return -1;
    }
};
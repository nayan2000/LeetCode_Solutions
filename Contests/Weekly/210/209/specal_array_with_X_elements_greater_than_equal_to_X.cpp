
class Solution {
public:
    int findGreater(vector<int> &nums, int x){
        int count = 0;
        for(auto &a : nums){
            if(a >= x) count++;
        }
        return count;
    }
    int specialArray(vector<int>& nums){
        
        int lo = 0;
        int hi = *max_element(nums.begin(), nums.end());
        for(int i = lo; i <= hi; i++){
            if(findGreater(nums, i) == i)
                return i;
        }
        return -1;
    }
};
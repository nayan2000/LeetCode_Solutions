class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = 1;
        int count = 0;
        while(i < n and j < n){
            if(i != j && nums[j] - nums[i] == k){
                count++;
                j++;
                i++;
                while(i > 0 and i < n and nums[i] == nums[i-1]) i++;
                while(j > 0 and j < n and nums[j] == nums[j-1]) j++;
            }
            else if(nums[j] - nums[i] > k)
                i++;
            else
                j++;
        }
        return count;
        
        
        // Count the elements with Counter
        // If k > 0, for each element i, check if i + k exist.
        // If k == 0, for each element i, check if count[i] > 1
    }
};
class Solution {
public:
    void combinationSumHelper(int start, int target, vector<int>& candidates, vector<int> &currSet, vector<vector<int>> &ans){
        if(target < 0) return;
        if(target == 0){
            ans.push_back(currSet);
            return;
        }
        for(int i = start; i < candidates.size(); i++){
            currSet.push_back(candidates[i]);
            combinationSumHelper(i, target - candidates[i], candidates, currSet, ans);
            currSet.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //My decision revolves around picking the first element of the solution
        vector<vector<int>> ans;
        vector<int> currSet;
        int start = 0;
        combinationSumHelper(start, target, candidates, currSet, ans);
        return ans;
    }
};
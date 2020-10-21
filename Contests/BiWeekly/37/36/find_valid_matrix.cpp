class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> ans(rowSum.size(), vector<int>(colSum.size(), 0));
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> r, c;
        for(int i = 0; i < rowSum.size(); i++){
            r.push({rowSum[i], i});
        }
        for(int i = 0; i < colSum.size(); i++){
            c.push({colSum[i], i});
        }
        
        while(!c.empty() && !r.empty()){
            auto [centry, col] = c.top();
            c.pop();
            auto [rentry, row] = r.top();
            r.pop();
            int rc = min(centry, rentry);
            ans[row][col] = rc;
            centry -= rc;
            rentry -= rc;
            if(centry) c.push({centry, col});
            if(rentry) r.push({rentry, row});
        }
        return ans;
    }
};
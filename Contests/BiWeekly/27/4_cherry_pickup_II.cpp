class Solution {
public:
    int cherryPickupHelper(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>> &dp){
        int m = grid.size();
        int n = grid[0].size();
        if(r == m) 
            return 0;
        
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        
        int res = 0;
        res = grid[r][c1];
        
        if(c1 != c2) //c1 and c2 are bound because of same depth
            res += grid[r][c2];
        
        int temp = 0, maxPossible = 0;
        int c1next, c2next;
        vector<int> pos = {-1, 0, 1};
        for(auto &x1 : pos){
            for(auto &x2 : pos){
                c1next = x1 + c1;
                c2next = x2 + c2;
                if(c1next >= 0 && c1next < n && c2next >= 0 && c2next < n)
                    maxPossible = max(maxPossible, cherryPickupHelper(grid, r+1, c1next, c2next, dp));
            }
        }
        
        res += maxPossible;
        dp[r][c1][c2] = res;
        // cout << res << endl;
        return res;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        
        return cherryPickupHelper(grid, 0, 0, n - 1, dp);
    }
};
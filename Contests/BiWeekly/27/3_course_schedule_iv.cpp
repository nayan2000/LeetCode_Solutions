class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        bool isConnected[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                isConnected[i][j] = false;
            }
        }
        for (auto &p : prerequisites)
            isConnected[p[0]][p[1]] = true;
        
        //floyd warshall --> 1e6
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    isConnected[i][j] = isConnected[i][j] || isConnected[i][k] && connected[k][j];
        
        vector<bool> ans;
        for (auto &q : queries)
            ans.push_back(connected[q[0]][q[1]]);
        return ans;
    }
};
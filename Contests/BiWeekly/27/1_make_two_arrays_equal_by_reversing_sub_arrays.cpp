class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int count[1001] = {0};
        for(auto &a : target)
            count[a]++;
        for(auto &b : arr)
            count[b]--;
        for(int i = 0; i < 1001; i++)
            if(count[i] != 0)
                return false;
        
        return true;
    }
};
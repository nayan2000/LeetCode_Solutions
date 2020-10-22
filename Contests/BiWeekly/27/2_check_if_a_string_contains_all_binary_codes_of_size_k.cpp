class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> visited;
        if(k > n) return false;
        int i = n - k;
        string temp = s.substr(i);
        visited.insert(temp);
        i--;
        //Going in reverse because CPP 
        //strings do not have O(1) pop from start
        for(; i >= 0; i--){
            temp = s[i] + temp;
            temp.pop_back();
            visited.insert(temp);
        }
        return visited.size() == 1<<k;
    }
};
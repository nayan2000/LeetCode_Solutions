class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> m;
        if(s.size() < 10) return {};
        vector<string> ans;
        int n = s.size();
        string temp = "";
        int i = n - 10;
        temp = s.substr(i, 10);
        m[temp]++;
        i--;
        while(i >= 0){
            temp = s[i] + temp;
            temp.pop_back();
            m[temp] += 1;
            if(m[temp] == 2)
                ans.push_back(temp);
            i--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
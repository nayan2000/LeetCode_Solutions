class Solution {
public:
    int convert(string time){
        int h = stoi(time.substr(0,2));
        int m = stoi(time.substr(3,2));
        
        int t = h * 60 + m;
        return t;
        
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        map<string, vector<int>> m;
        for(int i = 0; i < keyName.size(); i++){
            m[keyName[i]].push_back(convert(keyTime[i]));
        }
        
        for(auto &x : m){
            if(x.second.size() > 2)
                sort(x.second.begin(), x.second.end());
        }
        vector<string> ans;
        //for each person, just check if the condition is satisfied.
        for(auto &x : m){
            vector<int> times = x.second;
            if(times.size() > 2){
                for(int i = 2; i < times.size(); i++){
                    if(times[i] - times[i-1] <= 60 && times[i] - times[i-2] <= 60){
                        ans.push_back(x.first);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
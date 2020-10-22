class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        bool flag = false; //flag for two cases where incoming asteroid is destroyed 
                           //and shouldn't be pushed
        for(int i = 0; i < asteroids.size(); i++){
            //collision
            flag = false;
            while(!s.empty() and s.top() > 0 and asteroids[i] < 0){
                //both asteroids destroyed
                if(abs(s.top()) == abs(asteroids[i])){
                    s.pop();
                    flag = true;
                    break;
                }
                //incoming asteroid still intact
                else if(abs(s.top()) < abs(asteroids[i]))
                    s.pop();
                //incoming asteroid destroyed
                else if(abs(s.top()) > abs(asteroids[i])){
                    flag = true;
                    break;
                }
                    
            }
            //no collision
            if(!flag)
                s.push(asteroids[i]);
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
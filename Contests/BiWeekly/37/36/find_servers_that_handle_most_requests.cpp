class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        // Brute Force:
        // vector<vector<pair<long long, long long>>> serverTimes(k);
        // for(int i = 0; i < arrival.size(); i++){
        //     if(serverTimes[i%k].size() == 0)
        //         serverTimes[i%k].push_back({arrival[i], arrival[i] + load[i]});
        //     else{
        //         if(serverTimes[i%k][serverTimes[i%k].size() - 1].second <= arrival[i]){
        //              serverTimes[i%k].push_back({arrival[i], arrival[i] + load[i]});
        //         }
        //         else{
        //             int j = (i+1)%k;
        //             while(j != i%k){
        //                 if(serverTimes[j%k][serverTimes[j%k].size() - 1].second <= arrival[i]){
        //                     serverTimes[j%k].push_back({arrival[i], arrival[i] + load[i]});
        //                     break;
        //                 }
        //                 j = (j+1)%k;
        //             }
        //         }
        //     }
        // }
        // vector<int> ans;
        // int maxAns = 0;
        // for(auto &x : serverTimes){
        //     if(x.size() > maxAns){
        //         maxAns = x.size();
        //     }
        // }
        // int i = 0;
        // for(auto &x : serverTimes){
        //     if(x.size() == maxAns){
        //         ans.push_back(i);
        //     }
        //     i++;
        // }
        // return ans;

        //------------------------------------------------------------------------------------------------------------------
        
        // Optimized:
        vector<int> servers(k,0);
		// max number of processes scheduled
        int max_val = 0;
		
		// for priority queue to reclaim servers that are idle now
        // auto comp = [](pair<int,int>&a, pair<int,int>&b){
        //     return a.first > b.first;
        // };
		
		// priority queue stores {time when server will become free, server id}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int, int>>> pq;
		
		// set of available servers
        set<int> available;
		
        for(int i = 0; i < k; i++)
            available.insert(i);
			
        for(int i = 0; i < arrival.size(); i++){
            
			// if the time surpasses curr time reclaim server 
            while(!pq.empty() && pq.top().first <= arrival[i]){
                available.insert(pq.top().second);
                pq.pop();
            }
           
		   // if no server is available drop the request and continue
            if(available.empty())
                continue;
			
			// get the next available server
            auto itr = available.lower_bound(i%k);
			
			// wrap around
            if(itr == available.end()){
                itr = available.begin();
            }
           
		    // schedule the process
            servers[*itr]++;
            
            pq.push({arrival[i]+load[i], *itr});
            int val = *itr;
			
			// mark server as known available
            available.erase(val);
           
            max_val = max(max_val, servers[val]);

        }
     
        vector<int> ans;
		
		// get all busiest servers
        for(int i = 0; i < servers.size(); i++){
            if(servers[i] == max_val)
                ans.push_back(i);
        }
        
        return ans;
    }
};
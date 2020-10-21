class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        q = queue<int>();
    }
    
    int ping(int t) {
        int lower = max(0, t - 3000);
        int upper = t;
        q.push(t);
        while(q.front() < lower){
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
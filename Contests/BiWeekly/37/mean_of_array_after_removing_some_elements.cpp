class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size();
        int k = 0.05 * n;
    
        sort(arr.begin(), arr.end());
        int i;
        //skip first k elements
        for(i = 0; i < k; i++){}
        //sum from indices k...n-k
        double sum = 0;
        while(i < n - k){
            sum += arr[i];
            i++;
        }
        double ans = sum/(n - 2*k);
        return ans;
    }
};
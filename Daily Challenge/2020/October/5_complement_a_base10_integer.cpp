class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        long long k = floor(log2(n))+1;
        return ((1 << k) - 1) ^ n; 
    }
};
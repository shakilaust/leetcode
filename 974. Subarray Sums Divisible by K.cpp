class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        unordered_map < int, int > dp;
        int sum = 0, ans = 0;
        dp[0] = 1;
        for( int i = 0 ; i < A.size() ; i++ ) { 
            sum += A[i];
            sum = ( sum % K + K ) % K;
            ans += dp[sum];
            dp[sum]++;
        }
        return ans;
    }
};

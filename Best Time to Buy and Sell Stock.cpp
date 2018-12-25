class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if( sz == 0 ) return 0;
        int ans = 0;
        int mx = prices[sz-1];
        for( int i = sz - 2 ; i >= 0 ; i-- ) { 
            ans = max( ans, mx - prices[i] );
            mx = max( mx, prices[i]);
        }
        return ans;
    }
};

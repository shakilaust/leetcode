class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if( sz < 2  ) return 0;
        int k = min( 2, sz );
        vector < int > sell( k + 1 , 0 );
        vector < int > buy( k + 1 , -INT_MAX);
         
        for( int i = 0 ; i < sz ; i++ ) {
            buy[0] = max( buy[0] , -prices[i] );
            for( int j = 1 ; j <= k  ; j++ ) {
                buy[j] = max( buy[j] , sell[j-1] - prices[i] );
                sell[j] = max( sell[j] , buy[j] + prices[i] );
            }
        }
        
        return sell[k];
        
        
    }
};

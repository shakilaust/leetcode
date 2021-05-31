class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
       int sell = 0;
       int buy = -prices[0];
        for( int i = 1;  i < prices.size() ; i++ ) {
            sell = max( sell, prices[i] + buy - fee );
            buy = max( buy, sell - prices[i] );
        }
        
        return sell;
    }
};

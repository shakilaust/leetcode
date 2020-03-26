class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        bool dp[1505] = {false};
        dp[0] = true;
        
        int sum = 0;
        for( int i = 0 ; i < stones.size(); i++ ) { 

            sum += stones[i];
            for(int j = min(1500, sum) ; j >= stones[i] ; j-- ) { 
                dp[j] |= dp[j-stones[i]];
            }
        }
        
        for( int i = sum / 2 ; i > 0 ; i-- ) { 
            if( dp[i] == true ) { 

                return max( sum - i , i ) - min( sum - i , i );
            }
        }
        
        return 0;
    }
};



const int NX = 5005;

int dp[ NX ][ 2 ][ 2 ][ 2 ];



class Solution {
public:
    
    int inp[ NX ];
    int len;
    int DP( int pos, int canBuy, int canSell, int mustCool) {
        if( pos == len ) return 0;
        int &ret = dp[ pos ][ canBuy ][ canSell ][ mustCool ];
        if( ret != -1 ) {
            return ret;
        }
        if( mustCool ) {
            ret = DP( pos + 1, 1 , 0 , 0 );
        } else if( canSell ) {
            int selling = DP( pos + 1 , 0 , 0 , 1 ) + inp[ pos ];
            int notSelling = DP( pos + 1, 0 , 1 , 0 );
            ret = max( selling, notSelling );
        } else {
            int buying = DP( pos + 1 , 0 , 1 , 0 ) - inp[ pos ];
            int notBuying = DP( pos + 1, 1, 0 , 0 );
            ret = max( buying, notBuying );
        }
        
        return ret;
    }
    int maxProfit(vector<int>& prices) {
        len = prices.size();
        if( len == 0 ) return 0;
        for( int i = 0 ; i < len ; i++ ) {
            inp[i] = prices[i];
            for( int j = 0 ; j < 2 ; j++ ) {
                for( int k = 0 ; k < 2 ; k++ ) {
                    for( int l = 0 ; l < 2 ; l++ ) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        
        return DP( 0, 1, 0, 0 );
    }
};

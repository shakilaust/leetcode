class Solution {
public:
    int dp[ 20 ][ 10000 + 5 ], len, inp[ 20 ];
    int DP( int pos, int sum) {
        if( pos == len ) { 
            return sum == 5000 ? 0 : -1e8;
        }
        int &ret = dp[pos][sum];
        if( ret != -1 ) return ret;
        ret = DP( pos + 1 , sum );
        ret = max( ret, DP( pos + 1 , sum - inp[pos]));
        ret = max( ret, DP( pos + 1 , sum + inp[pos] ) + inp[pos]);
        return ret;
    }
    int tallestBillboard(vector<int>& rods) {
      len = rods.size();
      for( int i = 0 ; i < len ; i++ ) { 
            inp[i] = rods[i];
            for( int j = 0 ; j < 10005 ; j++ ) dp[i][j] = -1;
      }
      return DP(0, 5000);
    }
};

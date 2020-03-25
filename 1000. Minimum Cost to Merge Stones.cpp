

bool isPossible( int N, int K ) { 
    if( ( N - 1 ) % ( K - 1 ) == 0 ) return true;
    return false;
}


class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if( n == 1 ) return 0;
        if(!isPossible(n, K)) return -1; 
        vector < int > sum( n + 1 , 0 );
        for( int i = 1 ; i <= n ; i++ ) { 
            sum[i] = sum[i-1] + stones[i-1];
        }

        vector < vector < int > > dp( n , vector < int > ( n , 0 ) );
        
        for( int item = K - 1 ; item < n ; item++ ) { 
            
            for( int x = 0, y = item ; y < n ; y++, x++ ) { 

                if( item == K - 1 ) dp[x][y] = sum[y+1] - sum[x];
                else { 

                    dp[x][y] = INT_MAX;
                    for( int mid = x ; mid < y ; mid += ( K - 1 ) ) {
                        dp[x][y] = min( dp[x][y], dp[x][mid] + dp[mid+1][y]);
                    }
                    
                    if(isPossible(item + 1, K)) dp[x][y] += ( sum[y+1] - sum[x] );

                }
            }

        }
        
        return dp[0][n-1] == INT_MAX ? -1 : dp[0][n-1];
        
    }
};


const int NX = 105;

int dp[ NX ][ NX ][ NX ];

vector < int > b;

int DP( int l, int r, int cnt) { 

    if( l > r ) return 0;
    int &ret = dp[l][r][cnt];
    if( ret != -1 ) return ret;
    while( r > l && b[r] == b[r-1] ) { 
        cnt++;
        r--;
    }
    
    ret = DP(l , r-1 , 0 ) + ( cnt + 1 ) * ( cnt + 1 );
    
    for( int i = l ; i < r ; i++ ) { 
        if( b[r] == b[i] ) { 
            ret = max( ret, DP( l, i , cnt + 1 ) + DP( i + 1 , r - 1 , 0 ) );
        }
    }
    
    return ret;
}


class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int sz = boxes.size();
        b = boxes;
      
        for( int i = 0 ; i <= sz ; i++ ) { 
            for( int j = 0; j <= sz ; j++ ) { 
                for( int k = 0 ; k <= sz ; k++ ) { 
                    dp[i][j][k] = -1;
                }
            }
        }
        return DP( 0 , sz - 1 , 0 );
    }
};

int dp[605][105][105];
 vector < int > zeros, ones;


int DP( int pos, int sz, int m, int n) { 

    if( m == 0 && n == 0 ) return 0;
    if( pos >= sz ) return 0;
 //   cout << " pos " << pos << " " << sz << " " << m << " " << n << endl;
    int &ret = dp[pos][m][n];
    if( ret != -1  ) return ret;
    ret = DP( pos + 1, sz , m , n );
    if( ones[pos] <= n && zeros[pos] <= m ) { 
        ret = max( ret, DP( pos + 1 , sz , m - zeros[pos], n - ones[pos]) + 1);
    }
    
    return ret;

}
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        
       int sz = strs.size();
        
        for( int i = 0 ; i < sz ; i++ ) { 
            for( int z = 0 ; z <= m ; z++ ) { 
                for( int o = 0 ; o <= n ; o++ ) { 
                    dp[i][z][o] = -1;
                }
            }

        }
      
        zeros.clear();
        ones.clear();
        
        for( int i = 0 ; i < sz ; i++ ) { 
            int z = 0, o = 0;
            for( int j = 0 ; j < strs[i].size() ; j++ ) { 
                if( strs[i][j] == '0' ) { 
                    z += 1;
                } else o += 1;
            }
            
            zeros.push_back(z);
            ones.push_back(o);
    
        }

      
        return DP(0, sz, m, n );
        
    }
};

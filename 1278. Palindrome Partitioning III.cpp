class Solution {
public:
    int palindromePartition(string s, int k) {
        int sz = s.size();
        vector < vector < int > > need ( sz + 1 , vector < int > ( sz + 1, 0 ) );
        
          int dp[ sz + 1 ][ k + 1 ];
        
      

            for( int j = 0 ; j < sz ; j++ ) { 

                for( int part = 1 ; part <= k ; part++ ) { 
                    dp[j][part] = 10000000;
                }
            }
        
        for( int i = 0 ; i < sz ; i++ ) { 

            int prv = 0;
            for( int x = i , y = i + 1 ; x >= 0 && y < sz ; x--, y++ ) { 
                 need[x][y] = ( s[x] != s[y] ) + prv;
                 prv = need[x][y];
            }
            
            prv = 0;
             for( int x = i - 1 , y = i + 1 ; x >= 0 && y < sz ; x--, y++ ) { 
                 need[x][y] = ( s[x] != s[y] ) + prv;
                 prv = need[x][y];
            }
        }
        
        for( int i = 0 ; i < sz ; i++ ) { 

            for( int part = 1; part <= k ; part++ ) { 
        
                if( part == 1 ) { 
                    dp[i][part] = need[0][i];
                } else { 
                    
                    for( int j = i - 1 ; j >= 0 ; j-- ) { 

                        dp[i][part] = min( dp[i][part] , dp[j][part-1] + need[j+1][i]);
                    }

                }
            }

        }
        
      
        
        return dp[sz-1][k];
        
       
    }
};

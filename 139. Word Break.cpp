class Solution {
public:
    bool wordBreak(string s, vector<string>& W) {
        int sz = s.size();
        int nsz = W.size();
        vector < bool > dp ( sz + 1 , false );
        dp[ 0 ] = true;
        
        for( int i = 1 ; i <= sz ; i++ ) { 
    
            for( int j = 0; j < nsz && dp[i] == false; j++ ) { 
                
                int Wlen = W[j].size();
                int startingIdx = i - W[j].size();
                if( startingIdx >= 0 && dp[ startingIdx ]  ) {
                    if( s.substr(startingIdx , Wlen ) == W[j] ) { 
                        dp[i] = true;
                    }   
                }
            }
        }
        
        
        return dp[ sz ];
    }
};

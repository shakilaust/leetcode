

bool cmp(string &a, string &b) { 
    
    if(a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

bool ok(string a, string b) { 
    if( a.size() != b.size() - 1 ) return false;
   
    int oneAdd = 0;
    for( int i = 0 , j = 0 ; i < b.size() && j < a.size() && oneAdd < 2 ; i++  ) { 
        
        if(b[i] != a[j] ) oneAdd++;
        else j++;

    }
    
    return oneAdd < 2;
    
}




class Solution {
public:
    int longestStrChain(vector<string>& words) {
       
        int sz = words.size();
       
        sort(words.begin(), words.end(), cmp );
        int ans = 0;
        vector < int > dp( sz , 0 );
        for( int i = 0 ; i < sz ; i++ ) { 
            dp[i] = max( dp[i], 1 );
            ans = max( ans, dp[i] );
            for( int j = i + 1 ; j < sz ; j++ ) {
                if( ok(words[i] , words[j])) { 
                    dp[j] = max( dp[j], dp[i] + 1 );
                    ans = max( ans, dp[j] );
                }
            }
        }

        
       
        return ans;
    }
};

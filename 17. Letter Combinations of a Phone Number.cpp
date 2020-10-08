class Solution {
public:
    vector < char > graph[10];
    
    void dfs( int pos, string &digits, string now, vector < string > &ans) {
        if( pos == digits.size()) {
            ans.push_back(now);
            return;
        }
        
        int idx = digits[pos] - '0';
        
        for( int i = 0 ; i < graph[idx].size() ; i++ ) {
            dfs( pos + 1 , digits , now + graph[idx][i], ans );
        }
    }
    vector<string> letterCombinations(string digits) {
        int j = 0;
        int now = 2;
         for( int i = 0 ; i < 5 ; i++, now++ ) {
            for( int k = 0 ; k < 3 ; k++, j++ ) {
                graph[now].push_back( ( char ) ( 'a' + j ));
            }
        }
        
        for( int k = 0 ; k < 4 ; k++, j++ ) { 
             graph[now ].push_back( ( char ) ( 'a' + j ));
        }
        now++;
        for( int k = 0 ; k < 3 ; k++, j++ ) { 
             graph[now].push_back( ( char ) ( 'a' + j ));
        }
         now++;
         for( int k = 0 ; k < 4 ; k++, j++ ) { 
             graph[now].push_back( ( char ) ( 'a' + j ));
        }
        
        vector < string > ans;
        if( digits == "" ) {
            return ans;
        } else {
            dfs( 0 , digits, "", ans );
        }
        
        return ans;
        
        
        
    }
};

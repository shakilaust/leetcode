class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int sz = A.size();
        int freq[ 105 ][ 26 ] = {0};
        
        for( int i = 0 ; i < A.size() ; i++ ) { 
            for( char ch: A[i] ) { 
                freq[i][ch - 'a']++;
            }
        }
        
        vector < string > ans;
        
        for( int i = 0 ; i < 26 ; i++ ) { 
            
            string res = "";
            char ch = i + 'a';
            res += ch;
            int mn, f = 0;
            for( int j = 0 ; j < sz ; j++ ) { 
                if( f == 0 ) { 
                    mn = freq[j][i];
                } else mn = min( mn, freq[j][i]);
                f = 1;
            }
            
            for( int j = 0 ; j < mn ; j++ ) { 
                ans.push_back(res);
            }

        }
        
        return ans;
    }
};

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string a = "";
        string b = "";

        int cnt = 0;
        for( int i = S.size() - 1 ; i >= 0 ; i-- ) { 
            if( S[i] == '#' ) { 
                cnt++;
            } else { 
                if( cnt > 0 ) { 
                    cnt--;
                } else a += S[i];
            }
        }
        cnt = 0;
        for( int i = T.size() - 1 ; i >= 0 ; i-- ) { 
            if( T[i] == '#' ) { 
                cnt++;
            } else { 
                if( cnt > 0 ) { 
                    cnt--;
                } else b += T[i];
            }
        }
        
        return a == b;
    }
};

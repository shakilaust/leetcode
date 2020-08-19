class Solution {
public:
    int maxLength(vector<string>& arr) {
        int sz = arr.size();
        int mx = 0;
        for( int mask = 0 ; mask <= ( 1 << sz ) + 1 ; mask++ ) { 

            bool isPossible = true;
            int freq[26] = {0};
            int cnt = 0;
            
            for( int i = 0 ; i < sz && isPossible; i++ ) { 
                
                if( mask & ( 1 << i ) ) { 
                    for( char ch: arr[i]) { 
                        if( freq[ch-'a'] > 0 ) { 
                            isPossible = false;
                            break;
                        }
                        freq[ch - 'a'] = 1;
                        cnt++;
                    }
                }
            }
            
            if( isPossible ) { 
                mx = max( mx, cnt );
            }
        }
        return mx;
    }
};

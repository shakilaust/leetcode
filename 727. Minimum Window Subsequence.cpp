class Solution {
public:
    string minWindow(string S, string T) {
         int tSz = T.size();
         vector < int > chars[26];
        
        for( int i = 0 ; i < S.size() ; i++ ) { 
            chars[S[i] - 'a'].push_back(i);
        }

        int start , low, nxt = -1, from;
        int ans = INT_MAX;
        
        bool found = true;
        while( found ) { 
           found = false;
           int lookFor = 0;
           while( lookFor < tSz ) { 
                 int idx = T[lookFor] - 'a';
                 if(chars[idx].size() == 0 ) break;
                 low = lower_bound(chars[idx].begin(), chars[idx].end(), nxt) - chars[idx].begin();
                
                 if( low == chars[idx].size() ) { 
                    break;
                 }
                 if( lookFor++ == 0 ) { 
                     from = chars[idx][low];
                  } 
                  nxt = chars[idx][low] + 1;
                if( lookFor == tSz ) found = true;
           }
            
           if( found ) { 
                if( ans > nxt - from ) { 
                    ans = nxt - from;
                    start = from;
                }
                nxt = from + 1;
            }
        }
     
        return ans == INT_MAX ? "" : S.substr(start, ans);
    }
}; 

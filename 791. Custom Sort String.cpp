class Solution {
public:
    string customSortString(string S, string T) {
        string ans = T;
        int freq[26] = {0};
        for( int i = 0 ; i < T.size() ; i++ ) freq[T[i]-'a']++;
        int idx = 0;
        for( int i = 0 ; i < S.size() ; i++ ) { 
             if(freq[S[i]-'a']) { 
                for( int j = 0 ; j < freq[S[i]-'a'] ; j++ ) { 
                    ans[idx++] = S[i];
                    
                }
                 freq[S[i]-'a'] = 0;
            }
        }
        for( int i = 0; i < 26 ; i++ ) { 
            for( int j = 0 ; j < freq[i] ; j++ ) { 
                ans[idx++] = i + 'a';
            }
        }
        return ans;
    }
};

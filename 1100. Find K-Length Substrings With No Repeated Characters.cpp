class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int freq[26] = {0};
        int low = 0, ans = 0;
        for( int i = 0 ; i < S.size() ; i++ ) { 
            freq[S[i] - 'a']++;
            while(freq[S[i] - 'a'] > 1 ) freq[S[low++] - 'a']--;
            
            if( i - low + 1 == K ) { 
                ans++;
                freq[S[low++] - 'a']--;
            }

        }
        return ans;
    }
};

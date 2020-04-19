class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        for( int need = 1 ; need <= 26 ; need++ ) {
            int freq[26] = {0};
            int repeating = 0, uniqueChar = 0;
            int low = 0;
            for( int i = 0 ; i < s.size() ; i++ ) { 

                freq[s[i] - 'a']++;
                if( freq[s[i] - 'a'] == 1 ) uniqueChar++;
                if( freq[s[i] - 'a'] == k ) repeating++;
                
                while( uniqueChar > need ) { 
                    if( freq[s[low] - 'a'] == k ) repeating--;
                    if( freq[s[low] - 'a'] == 1 ) uniqueChar--;
                    freq[s[low] - 'a']--;
                    low++;
                }
                
                if( uniqueChar == need && repeating == uniqueChar ) {
                    ans = max( ans , i - low + 1 );
                }
            }
        }
        
        return ans;
    }
};

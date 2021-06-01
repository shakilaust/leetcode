class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int mxCount = 0;
        int ans = 0;
        for( int end = 0, start = 0; end < s.size() ; end++ ) {
            mxCount = max( mxCount, ++freq[s[end] - 'A']);
            while( end - start + 1 - mxCount > k ) {
                freq[s[start] - 'A']--;
                start++;
            }
            ans = max( ans, end - start + 1 );
        }
        
        return ans;
    }
};

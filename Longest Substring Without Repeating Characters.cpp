class Solution {

public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int sz = s.size();
        int low = 0, high = 0, ans = 0;
        while(high < sz ) {
            freq[s[high]]++;
            while(freq[s[high]] > 1 ) {
                freq[s[low++]]--;
            }
            ans = max( ans , high - low + 1 );
            high++;
        }
        return ans;
        
    }
};

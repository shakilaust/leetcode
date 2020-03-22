class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int uniqueChar = 0;
        int freq[255] = {0};
        int ans = 0, low = 0, high = 0;
        int sz = s.size();
        while( high < sz ) { 

            freq[s[high]]++;
            if( freq[s[high]] == 1 ) { 
                uniqueChar++;
                while( uniqueChar > 2 && low <= high ) { 

                    freq[s[low]]--;
                    if( freq[s[low]] == 0 ) uniqueChar--;
                    low++;
                }
            
            }
            if( uniqueChar <= 2 ) { 
                ans = max( ans, high - low + 1 );
            }
            
            high++;
        }
        
        return ans;
    }
};

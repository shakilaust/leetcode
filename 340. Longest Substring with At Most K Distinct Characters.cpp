class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        int ans = 0; 
        int low = 0, high = 0;
        int sz = s.size();
        vector < int > freq( 256, 0 );
        int uniqueChar = 0;
        while( high < sz ) {

            freq[s[high]]++;
            if( freq[s[high]] == 1 ) uniqueChar++;
            
            while( uniqueChar > k && low < high ) {

                freq[s[low]]--;
                if(freq[s[low]] == 0 ) uniqueChar--;
                low++;
            }
            
            if( uniqueChar <= k ) ans = max( ans, high - low + 1 );
            high++;
       }
       return ans;
        
    }
};

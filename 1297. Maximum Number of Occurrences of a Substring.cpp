class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int freq[26] = {0};
        int ans = 0;
        int uniqueChar = 0;
        int low = 0, high = 0;
        unordered_map < string, int > occurances;
        while( high < s.size() ) {
            int idx = s[high] - 'a';
            if( freq[idx] == 0 ) {
                uniqueChar++;
            }
            freq[idx]++;
            while( uniqueChar > maxLetters ) {
                idx = s[low] - 'a';
                if( freq[idx] == 1 ) uniqueChar--;
                freq[idx]--;
                low++;
            }
            int totalDistance = high - low + 1;
            while( totalDistance > minSize ) {
                    idx = s[low] - 'a';
                    if( freq[idx] == 1 ) uniqueChar--;
                    freq[idx]--;
                    low++;
                    totalDistance--;
            }
            if( totalDistance >= minSize && totalDistance <= maxSize ) {
                 string str = s.substr(low, totalDistance);
                occurances[str]++;
                if( ans < occurances[str] ) {
                    ans = occurances[str];
                }
            } 
            
            high++;
            
        }
        
        return ans;
    }
};

class Solution {
public:
    int numberOfSubstrings(string s) {
        int freq[3] = {0};
        
        int ans = 0;
        for( int l = 0 , i = 0 ; i < s.size() ; i++ ) { 
                
            freq[s[i] - 'a']++;
            while( freq[0] && freq[1] && freq[2] ) { 
                freq[s[l] - 'a']--;
                l++;
            }
            
            ans += l;
        }
        
        return ans;
    }
};

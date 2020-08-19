class Solution {
public:
    int minSteps(string s, string t) {
        int sz = s.size();
        
        int freq[26] = {0};
        
        for( int i = 0 ; i < sz ; i++ ) { 
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }   
        
        int res = 0;
        for( int i = 0 ; i < 26 ; i++ ) { 
            res += abs( freq[i] );
        }
        
        return res / 2;
    }
};

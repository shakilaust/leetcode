class Solution {
public:
    int titleToNumber(string s) {
        int ans = 0;
        int sz = s.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            ans = ans * 26;
            ans += ( s[i] - 'A' + 1 );
        }
        return ans;
    }
};

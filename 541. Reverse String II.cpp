class Solution {
public:
    string reverseStr(string s, int k) {
        string ans = "";
        bool flip = false;
        string tmp = "";
        for( int i = 0 ; i < s.size() ; i++ ) {
            if( i % k == 0 ) {
                if( flip ) {
                    reverse( tmp.begin(), tmp.end());
                }
                ans += tmp;
                tmp = "";
                
                flip = !flip;
            }
            tmp += s[i];
        }
        if( flip ) {
            reverse(tmp.begin(), tmp.end());
        }
        ans += tmp;
        return ans;
    }
};

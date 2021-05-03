class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int cnt = 0;
        for( char ch: s ) {
            if( ch == '(') cnt++;
            else if( ch == ')') cnt--;
            mx = max( mx, cnt );
        }
        
        return mx;
    }
};

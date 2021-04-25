class Solution {
public:
    long long int dfs( int &idx, string s) {
        
        long long int ans = 0;
        int neg = 0;
        long long int cur = 0;
        
        while( idx < s.size() ) {
            if( s[idx] == ')' ) {
                if( neg ) {
                    cur *= -1;
                }
                ans += cur;
                break;
            } else if( s[idx] == '(') {
                idx++;
                int v = dfs( idx, s );
                if( neg ) {
                    v *= -1;
                }
                ans += v;
                neg = 0;
            } else if( s[idx] >= '0' && s[idx] <= '9' ) {
                cur = ( cur * 10 ) + s[idx] - '0';
            } else if( s[idx] == '+' ) {
                if( neg ) {
                    cur *= -1;
                }
                ans += cur;
                cur = 0;
                neg = 0;
            } else if( s[idx] == '-' ) {
                if( neg ) {
                    cur *= -1;
                }
                ans += cur;
                cur = 0;
                neg = 1;
            } else {
                if( neg ) {
                    cur *= -1;
                }
                ans += cur;
                cur = 0;
            }
            
            if( idx + 1 == s.size() ) {
                if( neg ) {
                    cur *= -1;
                }
                ans += cur;
            }
            
            idx++;
        }
        return ans;
    }
    int calculate(string s) {
        int idx = 0;
        return dfs( idx, s );
    }
};

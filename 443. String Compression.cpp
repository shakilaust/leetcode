class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        for( int i = 1, cnt = 1 ; i <= chars.size() ; i++, cnt++ ) {
            if( i  == chars.size() || chars[i] != chars[i-1] ) {
                chars[idx++] = chars[i - 1];
                if( cnt >= 2 ) {
                    for( char digit: to_string(cnt)) {
                        chars[idx++] = digit;
                    }
                }
                cnt = 0;
                
            }
        }
        return idx;
    }
};

class Solution {
public:
    int maxPower(string s) {
        int ans = 0;
        char prv='$';
        int total = 0;
        for( char cur: s ) { 
            if( prv == cur ) {
                total++;
            } else total = 1;
            ans = max( ans, total);
            prv = cur;
        }
        return ans;
    }
};

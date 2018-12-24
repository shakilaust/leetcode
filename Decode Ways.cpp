class Solution {
public:
    bool ok( int decimal, int unit) { 
        if( decimal == 1 ) return true;
        if( decimal == 2 && unit <= 6 ) return true;
        return false;
    }
    int numDecodings(string s) {
        int sz = s.size();
        vector < int > dp;
        for( int i = 0 ; i <= sz ; i++ ) dp.push_back(0);
        dp[0] = 1;
        for( int i = 1 ; i <= sz ; i++ ) { 
           if(s[i-1] != '0' ) dp[i] += dp[i-1];
            if( i - 2 >= 0 && ok(s[i-2] - '0' , s[i-1] - '0' ) ) dp[i] += dp[i-2];
        }
        return dp[sz];
    }
};

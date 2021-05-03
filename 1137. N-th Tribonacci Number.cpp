class Solution {
public:
    int tribonacci(int n) {
        if( n == 0 ) return 0;
        if( n <= 2 ) return 1;
        
        vector < int > ans( n + 1 , 0 );
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 1;
        for( int i = 3 ; i <= n ; i++ ) {
            ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
        }
        
        
        return ans[n];
    }
};

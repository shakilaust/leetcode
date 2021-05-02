class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector < int > freq( 1005, 0 );
        int mx = 0;
        for( int x: target ) {
            mx = max( mx, x );
            freq[x]++;
        }
        for( int x: arr ) {
            mx = max( mx, x );
            freq[x]--;
        }
        for( int i = 0 ; i <= mx ; i++ ) {
            if( freq[i] != 0 ) {
                return false;
            }
        }
        return true;
    }
};

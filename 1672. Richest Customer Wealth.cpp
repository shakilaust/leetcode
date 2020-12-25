class Solution {
public:
    int maximumWealth(vector<vector<int>>& inp) {
        int ans = 0;
        int customers = inp.size();
        if( customers == 0 ) return ans;
        int banks = inp[0].size();
        for( int i = 0 ; i < customers ; i++ ) {
            int sum = 0;
            for( int j = 0 ; j < banks; j++ ) {
                sum += inp[i][j];
            }
            ans = max( ans, sum );
        }
        return ans;
    }
};

class Solution {
public:
    int maxSatisfaction(vector<int>& inp) {
        sort( inp.begin(), inp.end() );
        int ans = 0;
        int sz = inp.size();
        for( int i = 0 ; i < sz; i++ ) {
            int curSum = 0;
            for( int j = i, mul = 1; j < sz ; j++, mul++ ) {
                curSum += ( mul * inp[j] );
            }
            ans = max( ans, curSum );
        }
        return ans;
    }
};

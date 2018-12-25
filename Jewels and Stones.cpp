class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool isPresent[256] = {0};
        int jsz = J.size();
        for( int i = 0 ; i < jsz ; i++ ) isPresent[J[i]] = 1;
        int ans = 0, sSz = S.size();
        for( int i = 0 ; i < sSz ; i++ ) if( isPresent[S[i]]) ans++;
        return ans;
    }
};

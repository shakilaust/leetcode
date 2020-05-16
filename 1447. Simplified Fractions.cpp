class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector< string > ans;
        for( int lob = 1; lob < n ; lob++ ) {
            for( int hor = lob + 1 ; hor <= n ; hor++ ) {
                 if( gcd(lob, hor) > 1 ) continue;
                  string add = to_string(lob) + "/" + to_string(hor);
                  ans.push_back(add);
            }
        }
        return ans;
    }
};

bool cmp( pair < int, int> a, pair< int, int> b) {
        if( a.first == b.first ) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }

class Solution {
public:
    
    int maxWidthRamp(vector<int>& A) {
        vector < pair < int , int > > inp;
        for( int i = 0 ; i < A.size() ; i++ ) {
            inp.push_back({ A[i], i });
        }
        sort( inp.begin(), inp.end(), cmp );
        int mn = inp[0].second;
        int mx = 0;
        for( int i = 1; i < inp.size() ; i++ ) {
            mx = max( mx, inp[i].second - mn );
            mn = min( mn, inp[i].second );
        }
        return mx;
    }
};

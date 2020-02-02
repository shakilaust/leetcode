   bool cmp(const pair< int, int> &a, const pair< int, int> &b ) { 
        if( a.first == b.first ) return a.second < b.second;
        return a.first < b.first;

    }

class Solution {
public:
    vector < pair< int, int> > inp;
 
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector < int > ans;
        int sz = arr.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            inp.push_back( make_pair( abs(x - arr[i] ), arr[i] ));

        }
        sort( inp.begin(), inp.end(), cmp );
        for( int i = 0 ; i < sz && i < k ; i++ ) ans.push_back( inp[i].second );
        sort( ans.begin(), ans.end() );
        return ans;
    }
};

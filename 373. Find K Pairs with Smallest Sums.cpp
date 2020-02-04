bool cmp( pair< int, pair< int, int> > a, pair< int, pair< int, int> > b) { 
        
     
        return a.first < b.first;
}

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector < pair< int, pair< int, int> > > inp;
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        for( int i = 0; i < sz1 ; i++ ) {
            for( int j = 0 ; j < sz2 ; j++ ) { 
                inp.push_back( make_pair( nums1[i] + nums2[j] , make_pair( nums1[i] , nums2[j])));
            }
        }

        sort(inp.begin(), inp.end(), cmp );
        vector < vector < int > > ans;
        int sz = min( k , sz1 * sz2 );
        for( int i = 0 ; i < sz ; i++ ) { 
            vector < int > temp;
            temp.push_back( inp[i].second.first);
            temp.push_back(inp[i].second.second);
            ans.push_back(temp);
        }
        return ans;
    }
};

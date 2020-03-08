

bool cmp( pair< int, int > a, pair< int, int> b ) { 
    if( a.first == b.first ) return a.second > b.second;
    return a.first < b.first;

}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& inp) {
        int sz = inp.size();
        if( sz == 0 ) return 0;
        else if( sz == 1 ) return 1;
        vector < pair< int, int > > intervals;
        for( int i = 0; i < sz ; i++ ) { 
            intervals.push_back( make_pair(inp[i][0], 1) );
            intervals.push_back(make_pair(inp[i][1], 2 ) );
        }

        int ans = 0;
        int cnt = 0;
        sort( intervals.begin(), intervals.end(), cmp );
        for( int i = 0 ; i < intervals.size() ; i++ ) { 
            if( intervals[i].second == 2 ) cnt--;
            else cnt++;
            ans = max( ans, cnt );
        }
        
        return ans;
      
        
        
    }
};

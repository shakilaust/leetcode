
bool cmp(vector<int> &a, vector< int > &b) { 
    if(a[1] == b[1] ) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int sz = intervals.size();
        if( sz == 0 )    return 0;
        sort( intervals.begin(), intervals.end(), cmp);
        int finish = intervals[0][1];
        int ans = 0 ; 
        
        for( int i = 1 ; i < intervals.size(); i++ ) { 
            if( finish > intervals[i][0] ) { 
                ans++;
            } else finish = intervals[i][1];

        }
        
        return ans;
    }
};

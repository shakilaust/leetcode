
bool cmp(vector < int > &a, vector < int > &b) {
    if( a[1] == b[1] ) return a[0] < b[0];
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int sz = points.size();
        if( sz < 2 ) return sz;
        sort( points.begin(), points.end(), cmp );
        int endTime = points[0][1];
        int ans = 1;
        for( int i = 1; i < sz ; i++ ) {
            if( endTime < points[i][0] ) {
                endTime = points[i][1];
                ans++;
            }
        }
        
        return ans;
        
        
    }
};

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map < int , set < int > > mp;
        for( vector < int > p: points ) {
            mp[p[0]].insert(p[1]);
        }
        
        int sz = points.size();
        int ans = INT_MAX;
        for( int i = 0 ; i < sz ; i++ ) {
            for( int j = i + 1 ; j < sz ; j++ ) {
                if( points[i][0] == points[j][0] || points[i][1] == points[j][1] ) {
                    continue;
                }
                
                if( mp[points[i][0]].count(points[j][1]) && mp[points[j][0]].count(points[i][1])) {
                    int rec = abs( points[i][0] - points[j][0] ) * abs( points[i][1] - points[j][1] );
                    ans = min( ans, rec );
                    
                }
            }
        }
        
        
        return ans == INT_MAX ? 0 : ans ;
    }
};

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        map < int, int > value;
        map < int , int > :: iterator it;
        int row = wall.size();
        int mx = 0;
        for( int i = 0 ; i < row ; i++ ) {
            int sz = wall[i].size();
            int total = 0;
            for( int j = 0 ; j < sz ; j++ ) {
                total += wall[i][j];
                if( j + 1 != sz )
                    value[total]++;
            }
            mx = max( total, mx );
        }

        int ans = row;
        for( it = value.begin(); it != value.end(); it++ ) { 
            ans = min( ans, row - it->second);
        }
        return ans;
    }
};

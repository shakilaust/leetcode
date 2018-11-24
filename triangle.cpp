class Solution {
int dx[2] = {-1, -1};
int dy[2] = {-1, 0};
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int ans, sz = triangle.size();
        for( int i = 0; i < sz ; i++ ) { 

            for( int j = 0 ; j <= i ; j++ ) { 
                 int f = 1, minValue = 0;
                 for( int k = 0 ; k < 2 ; k++ ) { 
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if( nx >= 0 && ny < i && ny >= 0 ) {
                        if( f ) minValue = triangle[nx][ny];
                        else minValue = min( minValue, triangle[nx][ny]);
                        f = 0;
                    }
                 }
                triangle[i][j] += minValue;
                if( i == sz - 1 ) {
                    ans = j == 0 ? triangle[i][j] : min( ans, triangle[i][j]);
                }
            }
        }
        return ans;
        
    }
};

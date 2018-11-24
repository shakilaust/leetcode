class Solution {



public:
    int dx[2] = {0, -1};
    int dy[2] = {-1, 0};
    bool Possible( int x, int y, int row, int col ) {
        if( x < 0 || x >= row || y < 0 || y >= col ) return false;
        return true;
    }
    int minPathSum(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        for( int i = 0 ; i < row ; i++ ) 
        {
            for( int j = 0 ; j < col ; j++ ) {
                if( i == 0 && j == 0 ) continue;
                int f = 1, minValue = 0;
                for( int k = 0 ; k < 2 ; k++ ) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(Possible(nx, ny, row, col)){ 
                        if( f ) minValue = grid[i][j] + grid[nx][ny];
                        else minValue = min(minValue, grid[i][j] + grid[nx][ny]);
                        f = 0;
                    }
                }
                grid[i][j] = minValue;
                
            }
        }
        return grid[row-1][col-1];
        
    }
};



class Solution {
public:
    
 
    
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        vector < vector < int > > ans( rows );
        if( rows == 0 ) return ans;
        int cols = mat[0].size();
        vector < vector < int > > sum( rows , vector < int > ( cols, 0 ) );
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                 int upperCorner = row - 1 >= 0 && col - 1 >= 0 ? sum[row-1][col-1] : 0;
                 int up = row - 1 >= 0 ? sum[row-1][col] : 0;
                 int lft = col - 1 >= 0 ? sum[row][col-1] : 0;
                 sum[row][col] = ( lft + up - upperCorner ) + mat[row][col];
            }
        }
        
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                int upperRow = row - k;
                int upperCol = col - k;
                int lowerRow = row + k >= rows ? rows - 1 : row + k;
                int lowerCol = col + k >= cols ? cols - 1 : col + k;
                int sumCompleteBox = sum[lowerRow][lowerCol];
                int outSideCornerBox = row - k - 1 >= 0 && col - k - 1 >= 0 ? sum[row-k-1][col-k-1] : 0;
                int lft = upperCol - 1 >= 0 ? sum[lowerRow][upperCol - 1] : 0 ;
                int up = upperRow - 1 >= 0 ? sum[upperRow - 1][lowerCol] : 0 ;
                int res = ( sumCompleteBox + outSideCornerBox ) - ( lft + up );
                ans[row].push_back( res );
            }
        }
        
        
        
        return ans;
        
        
    }
};

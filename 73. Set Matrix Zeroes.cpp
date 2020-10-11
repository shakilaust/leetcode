class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set < int > zeroRow, zeroCol;
        int rows = matrix.size();
        if( rows == 0 ) return;
        int cols = matrix[0].size();
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( matrix[row][col] == 0 ) {
                    zeroRow.insert(row);
                    zeroCol.insert(col);
                }
            }
        }
        
        for( int row: zeroRow ) {
            for( int col = 0 ; col < cols ; col++ ) {
                matrix[row][col] = 0;
            }
        }
        
        for( int col: zeroCol ) {
            for( int row = 0 ; row < rows ; row++ ) {
                matrix[row][col] = 0;
            }
        }
    }
};

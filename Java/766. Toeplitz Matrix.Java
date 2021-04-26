class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int rows = matrix.length;
        if( rows == 0 ) return true;
        int cols = matrix[0].length;
        
        for( int col = 0 ; col < cols ; col++ ) {
            int v = matrix[0][col];
            for( int x = 1, y = col + 1 ; x < rows && y < cols ; x++, y++ ) {
                if( v != matrix[x][y] ) {
                    return false;
                }
            }
        }
        
        for( int row = 1 ; row < rows ; row++ ) {
            int v = matrix[row][0];
            for( int x = row + 1, y = 1 ; x < rows && y < cols ; x++, y++ ) {
                if( v != matrix[x][y] ) {
                    return false;
                }
            }
        }
        
        return true;
    }
}

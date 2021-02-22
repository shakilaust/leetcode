class Solution {
    public int minPathSum(int[][] grid) {
        int rows = grid.length;
        if( rows == 0 ) return 0;
        int cols = grid[0].length;
        
        
        for( int r = 0 ; r < rows ; r++ ) {
            for( int c = 0 ; c < cols ; c++ ) {
                if( r == 0 && c == 0 ) continue;
                else if( r == 0 ) grid[r][c] += grid[r][c-1];
                else if( c == 0 ) grid[r][c] += grid[r-1][c];
                else grid[r][c] += Math.min(grid[r-1][c], grid[r][c-1]);
            }
        }
        
        
        return grid[rows-1][cols-1];
    }
}

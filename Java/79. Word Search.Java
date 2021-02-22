class Solution {
    
    public boolean[][] vis;
    public char[][] graph;
    public int[] dx = new int[] {1, -1, 0, 0};
    public int[] dy = new int[] {0, 0, 1, -1};
    
    int rows, cols; 
    
    
    public  boolean isOk( int x, int y ) {
        if( x >= 0 && x < rows && y >= 0 && y < cols && vis[x][y] == false ) return true;
        return false;
    }
    
    public boolean dfs(int x, int y, int matchSoFar, String word ) {
        if( matchSoFar == word.length() ) return true;
        vis[x][y] = true;
        for( int i = 0 ; i < 4 ; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( isOk( nx, ny ) && word.charAt(matchSoFar) == graph[nx][ny] && dfs( nx, ny, matchSoFar + 1 , word ) ) {
                return true;
            }
        }
        vis[x][y] = false;
        return false;
    }
    public boolean exist(char[][] board, String word) {
        graph = board;
        rows = board.length;
        if( rows == 0 ) {
            return word == "";
        }
        cols = board[0].length;
        vis = new boolean[rows][cols];
        
        for( int i = 0 ; i < rows; i++ ) {
            for( int j = 0 ; j < cols ; j++ ) {
                if( word.charAt(0) == board[i][j] && dfs( i , j , 1 , word) ) {
                    return true;
                }
            }
        }
        
        return false;
        
    }
}

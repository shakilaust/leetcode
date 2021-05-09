int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};



class Solution {
public:
    
    int rows, cols;
    void dfs( int x, int y, vector< vector< int> >&graph, int c) {
        graph[x][y] = c;
        for( int i = 0 ; i < 4 ; i++ ) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( nx >= 0 && nx < rows & ny >= 0 && ny < cols && graph[nx][ny] == 1 ) {
                dfs( nx, ny, graph, c );
            }
        }
    }
    int shortestBridge(vector<vector<int>>& A) {
        rows = A.size();
        if( rows == 0 ) return 0;
        cols = A[0].size();
        vector < vector < int > > costs( rows, vector < int > ( cols, INT_MAX ));
        
        int ans = INT_MAX;
        
        int color = 2;
        for( int row = 0 ; row < rows ; row++ ) {
            for(int col = 0 ; col < cols; col++ ) {
                if( A[row][col] == 1 ) {
                    dfs( row, col, A, color );
                   color++;
                }
            }
        }
        queue < int > X, Y;
        queue < int > from, cost;
        for( int row = 0 ; row < rows; row++ ) {
            for( int col = 0 ; col < cols; col++ ) {
                if( A[row][col] > 0 ) {
                    X.push( row );
                    Y.push( col );
                    costs[row][col] = 0;
                    cost.push( 0 );
                    from.push( A[row][col] );
                }
            }
        }
        
        bool found = false;
        while( !X.empty() ) {
            int curRow = X.front();
            int curCol = Y.front();
            int curCost = cost.front();
           
            int frm = from.front();
           
            X.pop();
            Y.pop();
            cost.pop();
            from.pop();
            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = curRow + dx[i];
                int ny = curCol + dy[i];
            
                if( nx >= 0 && nx < rows && ny >= 0 && ny < cols ) {
                 
                    if( A[nx][ny] == 0 ) {
                      
                        cost.push( curCost + 1 );
                        A[nx][ny] = frm;
                        from.push( frm );
                        X.push( nx );
                        Y.push( ny );
                        costs[nx][ny] = curCost + 1;
                    } else if( A[nx][ny] != frm ) {
                        
                        ans = min( ans , costs[nx][ny] + costs[curRow][curCol]);
                    }
                }
            }
        }
        
                
            
        
        
        return ans;
        
    }
};

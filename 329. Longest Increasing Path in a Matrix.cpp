class Solution {
public:
    vector < vector < int > > dp;
    vector < vector < int > > graph;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int row, column;
    
    void initialization( vector < vector < int > >& matrix ) { 
        for( int i = 0 ; i < row ; i++ ) { 
            vector < int > dummy, cloneRow;
            for( int j = 0 ; j < column ; j++ ) { 
                dummy.push_back(0);
                cloneRow.push_back(matrix[i][j]);
            }
            dp.push_back(dummy);
            graph.push_back(cloneRow);
        }

    }
    
    bool isInside( int x, int y) { 
        if( x >= 0 && x < row && y >= 0 && y < column ) { 
            return true;
        }
        return false;
    }
    
    int dfs( int x, int y) { 
        
        if( dp[x][y] > 0 ) return dp[x][y];
        
        dp[x][y] = 1;
        int mx = 0;
        for( int i = 0 ; i < 4 ; i++ ) { 
            int nx = x + dx[i];
            int ny = y + dy[i];
            if( isInside(nx, ny) ) { 
                if(graph[nx][ny] > graph[x][y] ) mx = max( mx, dfs(nx, ny));
            }
            
        }
        return dp[x][y] += mx;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        row = matrix.size();
        if( row == 0 ) return 0;
        column = matrix[0].size();
       
       
        initialization(matrix);
        int ans = 0;
        for( int i = 0 ; i < row ; i++ ) { 

            for( int j = 0 ; j < column ; j++ ) { 

                if( dp[i][j] == 0 ) { // not visited
                   ans = max( ans, dfs( i , j ) );
                }
            }
        }
        
        return ans;
    }
};

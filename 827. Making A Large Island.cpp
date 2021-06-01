int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
class Solution {
public:
    
    vector < vector < int > > visit;
    int rows, cols;

    
    vector < vector < int > > graph, group;
    bool ok( int row, int col ) {
        if( row >= 0 && row < rows && col >= 0 && col < cols ) {
            return true;
        }
        return false;
    }
    int dfs( int row, int col, int color, int v, int g) {
        graph[row][col] = color;
        visit[row][col] = v;
        int cnt = 1;
        group[row][col] = g;

        for( int i = 0 ; i < 4 ; i++ ) {
            int nx = row + dx[i];
            int ny = col + dy[i];
           
            if( ok( nx, ny) && graph[nx][ny] > 0 && visit[nx][ny] != v ) {
                cnt += dfs( nx, ny, color, v, g );
            }
        }
        return cnt;
      
    }
    
    void ini(vector < vector < int > > &grid) {
        graph.resize(rows);
        visit.resize(rows);
        group.resize(rows);
        for( int i = 0 ; i < rows ; i++ ) {
            graph[i].clear();
            visit[i].clear();
            group[i].clear();
            for( int j = 0 ; j < cols ; j++ ) {
                visit[i].push_back(0);
                group[i].push_back(INT_MIN);
                graph[i].push_back(grid[i][j]);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        if( rows == 0 ) return 0;
        cols = grid[0].size();
        int ans = 0;
        ini( grid );
        int g = 1;
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( graph[row][col] == 1 && visit[row][col] == 0 ) {
                    int color = dfs( row, col, 1, 1, g );
                   // cout << " color " << color << endl;
                    ans = max( ans, color );
                    dfs( row, col, color, 2, g );
                    g++;
                }
            }
        }
        
     
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( graph[row][col] == 0 ) {
                    int add = 1;
                    set < int > grp;
                    for( int i = 0 ; i < 4 ; i++ ) {
                        int nx = row + dx[i];
                        int ny = col + dy[i];
                        if( nx >= 0 && nx < rows && ny >= 0 && ny < cols && graph[nx][ny] > 0 ) {
                            if( grp.find( group[nx][ny]) == grp.end()) {
                                add += graph[nx][ny];
                                grp.insert(group[nx][ny]);
                            }
                        }
                    }
                    
                    ans = max( ans, add );
                }
            }
        }
        
        return ans;
        
    }
};

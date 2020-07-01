int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
public:
    
    int rows, columns;

    queue < pair< int, int > > q;
    queue < int > cost;
    int  bfs( vector<vector<int>>& grid ) { 
        
        int ans = 0;
        while(!q.empty()) { 

            pair< int , int > now = q.front();
            int prvCost = cost.front();
            q.pop();
            cost.pop();
            ans = max( ans, prvCost);
            
            for( int i = 0 ; i < 4 ; i++ ) { 
                int nx = dx[i] + now.first;
                int ny = dy[i] + now.second;
                
                if( nx < 0 || nx >= rows || ny < 0 || ny >= columns || grid[nx][ny] != 1 ) {
                    continue;
                }
                
                q.push( make_pair(nx , ny));
                cost.push(prvCost + 1);
                grid[nx][ny] = 2;
                
                

            }
        }
        return ans;
    }
    
    bool isInValid(vector<vector<int>>& grid) { 

            for( int row = 0 ; row < rows ; row++ ) { 

                for( int col = 0 ; col < columns ; col++ ) { 

                    if( grid[row][col] == 1 ) { 
                        return true;
                    }
                }
            }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        rows = grid.size();
        columns = grid[0].size();
        
        for( int i = 0 ; i < rows ; i++ ) { 

            for( int j = 0 ; j < columns ; j++ ) { 

                if( grid[i][j] == 2 ) { 

                    q.push(make_pair(i, j));
                    cost.push(0);
                }
            }
        }
        int ans = bfs(grid);
        return isInValid(grid) ? -1 : ans;
    }
};


bool inside( int x, int y, int row, int column) { 
    
    if( x >= 0 && x < row && y >= 0 && y < column ) { 
        return true;
    }
    return false;
}
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int row = grid.size();
        if( row == 0 ) { 
            return ans;
        }
        int column = grid[0].size();
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        for( int i = 0 ; i < row ; i++ ) { 
            for( int j = 0 ; j < column ; j++ ) { 
                if( grid[i][j] == '1') { 
                    queue < int > x, y;
                    x.push(i);
                    y.push(j);
                    ans++;
                    grid[i][j] = '0';
                    while( !x.empty() ) { 
                        int curX = x.front();
                        int curY = y.front();
                        x.pop();
                        y.pop();
                        for( int k = 0 ; k < 4 ; k++ ) { 

                            int nx = curX + dx[k];
                            int ny = curY + dy[k];
                            if( inside( nx, ny, row, column) && grid[nx][ny] == '1') { 
                                grid[nx][ny] = '0';
                                x.push(nx);
                                y.push(ny);
                            }   
                        }
        
                    }
                }
            }
        }
        return ans;
    }
};

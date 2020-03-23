class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();
        vector < int > row( rows );
        vector < int > column( columns );
        
        for( int r = 0 ; r < rows; r++ ) { 

            for( int c = 0 ; c < columns; c++ ) { 
                
                if( c == 0 || row[r] < grid[r][c] ) { 
                    row[r] = grid[r][c];
                }

            }
        }

         for( int c = 0 ; c < columns ; c++ ) { 

            for( int r = 0 ; r < rows; r++ ) { 
                
                if( r == 0 || column[c] < grid[r][c] ) { 
                    column[c] = grid[r][c];
                }

            }
        }

        int ans = 0 ;
        for( int r = 0 ; r < rows; r++ ) { 
            for( int c = 0 ; c < columns ; c++ ) { 
                ans += ( min(row[r], column[c]) - grid[r][c]);
            }
        }
        return ans;
    }
};

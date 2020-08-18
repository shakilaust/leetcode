class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int columns = grid[0].size();
        vector < int > row ( rows, 0 );
        vector < int > col( columns , 0 );
        
        for( int i = 0 ; i < rows ; i++ ) { 
            for( int j = 0 ; j < columns ; j++ ) { 
                if( grid[i][j] == 1 ) { 
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for( int i = 0 ; i < rows ; i++ ) { 

            for( int j = 0 ; j < columns ; j++ ) { 
                if( grid[i][j] && (row[i] > 1 || col[j] > 1) ) ans++;
            }
        }
        
        return ans;
    }
};

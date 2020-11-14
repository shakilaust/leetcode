class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        if( rows == 0 ) return mat;
        int cols = mat[0].size();
        
        for( int i = 0 ; i < 2 ; i++ ) {
            // i : 0 ( row ), 1 ( col )
            int jsz = i ? cols : rows;
            for( int j = 0 ; j < jsz ; j++ ) {
                int x = i ? 0 : j;
                int y = i ? j : 0;
              
                vector < int > values;
                while( x < rows && y < cols ) {
                    values.push_back(mat[x][y]);
                    x++;
                    y++;
                }
                
                sort( values.begin(), values.end());
                
                 x = i ? 0 : j;
                 y = i ? j : 0;
                 int idx = 0;
                 while( x < rows && y < cols ) {
                    mat[x][y] = values[idx++];
                    x++;
                    y++;
                }
                 
                
            }
            
            
        }
        
        return mat;
    }
};

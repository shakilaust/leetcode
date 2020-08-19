class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int columns = matrix[0].size();
        vector < vector < int > > dp( rows + 1 , vector < int > ( columns + 1 ,  0 ) );
        
        int res = 0;
        for( int row = 0 ; row < rows ; row++ ) { 
            for( int col = 0 ; col < columns ; col++ ) { 

                if( matrix[row][col] == 1 ) { 
                    if( row - 1 >= 0 && col - 1 >= 0 ) { 
                        dp[row][col] = min( min( dp[row-1][col], dp[row][col-1]), dp[row-1][col-1]) + 1;
                    } else { 
                        dp[row][col] = 1;
                    }
                }
                
                res += dp[row][col];
            }

        }
        
        return res;
    }
};

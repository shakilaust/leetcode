class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector< int > > ans( n , vector < int > ( n , 0 ) );
        
        int rowStart = 0, rowEnd = n - 1;
        int colStart = 0, colEnd = n - 1;
        int cur = 1;
        while( rowStart <= rowEnd && colStart <= colEnd ) { 

            for( int row = rowStart, col = colStart ; col <= colEnd ; col++ ) { 
                ans[row][col] = cur++;
            }

            for( int row = rowStart + 1, col = colEnd ; row <= rowEnd ; row++ ) { 

                ans[row][col] = cur++;
            }


            for( int col = colEnd - 1, row = rowEnd ; col >= colStart ; col-- ) { 

                ans[row][col] = cur++;
            }
            
            for( int row = rowEnd - 1 , col = colStart; row > rowStart ; row-- ) { 
                ans[row][col] = cur++;
            }
            rowStart++;
            colStart++;
            rowEnd--;
            colEnd--;
        }
        
        
        return ans;
    }
};

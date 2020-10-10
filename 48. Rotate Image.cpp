class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if( rows == 0 ) return;
        int cols = matrix[0].size();
        if( rows == 1 && cols == 1 ) return;
        int mnRow = 0, mxRow = rows - 1;
        int mnCol = 0, mxCol = cols - 1;
        
        while( mxRow >= mnRow && mxCol >= mnCol ) {
            vector < int > values;
            // step 1 : minCol to mxCol; mnRow
            for( int col = mnCol ; col <= mxCol ; col++ ) {
                values.push_back( matrix[mnRow][col] );
            }
            
            // Step 2 : mnRow + 1 , mxRow; col : mxCol
            for( int row = mnRow + 1 ; row <= mxRow ; row++ ) {
                values.push_back( matrix[row][mxCol] );
            }
            
            // step 3: mxCol - 1 to mnCol , mxRow 
            for( int col = mxCol - 1 ; col >= mnCol ; col-- ) {
                values.push_back( matrix[mxRow][col] );
            }
            
            // step 4: mxRow - 1 to mnRow - 1, mnCol 
            for( int row = mxRow - 1 ;  row > mnRow ; row-- ) {
                values.push_back(matrix[row][mnCol] );
            }
            
            int idx = 0;
            
            // step 1: mnRow to mxRow , mxCol
            for( int row = mnRow ; row <= mxRow ; row++ ) {
                matrix[row][mxCol] = values[idx++];
            }
            // step 2: mXCol - 1 , mnCol, mxRow
            for( int col = mxCol - 1  ; col >= mnCol ; col-- ) {
                matrix[mxRow][col] = values[idx++];
            }
            
            // step 3: mxRow - 1, mnRow 
            for( int row = mxRow - 1 ; row >= mnRow ; row-- ) {
                matrix[row][mnCol] = values[idx++];
            }
            
            // step 4: mnCol + 1 , mxCol - 1, mnRow 
            for( int col = mnCol +  1 ; col < mxCol ; col++ ) {
                matrix[mnRow][col] = values[idx++];
            }
            
            mnRow++;
            mxRow--;
            mnCol++;
            mxCol--;
        }
    }
};

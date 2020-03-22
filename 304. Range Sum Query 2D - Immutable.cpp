class NumMatrix {
   vector < vector < long long int > > sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()) { 
            sum.clear();
            return;
        }
        int rows = matrix.size();
        int columns = matrix[0].size();
        sum.resize(rows + 1 );
        for( int i = 0 ; i <= rows ; i++ ) { 
            sum[i].resize(columns + 1, 0);
        }
        
        for( int i = 1 ; i <= rows; i++ ) { 

            for( int j = 1 ; j <= columns ; j++ ) { 

                sum[i][j] = ( sum[i-1][j] + sum[i][j-1] + matrix[i-1][j-1] ) - sum[i-1][j-1];
            }
        }

        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if( sum.empty() ) return 0;
        long long int full = sum[row2 + 1][ col2 + 1];
        full = full - sum[row2 + 1][col1];
        full = full - sum[row1 ][ col2 + 1];
        full = full + sum[row1][col1];
        return full;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

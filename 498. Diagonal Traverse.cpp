class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int add[] = {-1, 1};
        int row = 0, col = 0;
        int idx = 0;
        vector < int > ans;
        int rows = matrix.size();
        if( rows == 0 ) {
            return ans;
        }
        int cols = matrix[0].size();
        bool addInCol = true;
        int total = rows * cols;
        while( total > ans.size() ) {
            
            
            while( true ) {
                ans.push_back(matrix[row][col]);
                int nxtRow = row + add[idx];
                int nxtCol = col + add[1 - idx];
                
                if( nxtRow >= rows || nxtCol >= cols || nxtRow < 0 || nxtCol < 0 ) {
                    break;
                }
                row = nxtRow;
                col = nxtCol;
            }
            
            idx = 1 - idx;
            
            
            if( addInCol ) {
                col = col + 1;
                if( col == cols ) {
                    col = cols - 1;
                    row = row + 1;
                }
            } else {
                row = row + 1;
                if( row == rows ) {
                    row = rows - 1;
                    col = col + 1;
                }
            }
            
            addInCol = !addInCol;
        } 
        
        return ans;
    }
};

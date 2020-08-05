class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if( rows == 0 ) return false;
        int cols = matrix[0].size();
        int row = rows - 1;
        int col = 0;
        
        while( row >= 0 && col < cols ) { 
            
            if( matrix[row][col] > target ) { 
                row--;
            } else if( matrix[row][col] < target ) { 

                col++;
            } else return true;

        }
        
        return false;
    }
};

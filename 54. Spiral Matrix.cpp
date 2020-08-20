class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector < int > ans;
        int rows = matrix.size();
        if( rows == 0 ) { 
            return ans;
        }
        int cols = matrix[0].size();
        int rowMin = 0, rowHigh = rows - 1;
        int colMin = 0, colHigh = cols - 1;
      
        while( rowMin <= rowHigh && colMin <= colHigh ) { 
            // take rowMin row completely
            for( int i = colMin ; i <= colHigh ; i++ ) { 
                ans.push_back(matrix[rowMin][i]);
            }
            
            // take ColHigh value
            for( int i = rowMin + 1 ; i <= rowHigh ; i++ ) { 
                ans.push_back(matrix[i][colHigh]);
            }
            
            // take rowHigh value
            if( rowHigh != rowMin ) {
                for( int i = colHigh - 1 ; i >= colMin ; i-- ) { 
                    ans.push_back(matrix[rowHigh][i]);
                }
            }
            
            // take colMin values
            if( colMin != colHigh ) {
                for( int i = rowHigh - 1 ; i > rowMin ; i-- ) { 
                    ans.push_back(matrix[i][colMin]);
                }
            }
            
            
            colMin++;
            colHigh--;
            rowMin++;
            rowHigh--;
        }
        
        return ans;
    }
};

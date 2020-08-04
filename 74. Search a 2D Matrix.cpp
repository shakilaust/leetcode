class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if( rows == 0 ) return false;
        int col = matrix[0].size();
        int low = 0, high = rows * col - 1;
        int mid, midElement;
        while( low <= high ) { 

            mid = ( low + high ) / 2;
            midElement = matrix[mid / col ][ mid % col ];
            if( midElement == target ) return true;
            if( midElement > target ) { 
               high = mid - 1;
            } else low = mid + 1;
        }
        
        return false;
    }
};

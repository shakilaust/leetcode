
class Solution {
public:
  
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue < int > pq;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for( int row = 0 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols ; col++ ) {
                if( pq.size() < k ) pq.push(matrix[row][col]);
                else {
                    if( pq.top() > matrix[row][col] ) {
                        pq.pop();
                        pq.push(matrix[row][col]);
                    }
                }
            }
        }
        
        return pq.top();
    }
};

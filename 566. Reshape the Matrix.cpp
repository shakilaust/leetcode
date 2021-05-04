class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
       vector <  vector < int > > ans;
       vector < int > rowAdd;
        int rows = mat.size();
        if( rows == 0 ) {
            return ans;
        }
        int cols = mat[0].size();
        if( rows * cols != r * c ) {
            return mat;
        }
        for( int row = 0, insert = 1 ; row < rows ; row++ ) {
            for( int col = 0 ; col < cols; col++ ) {
                rowAdd.push_back(mat[row][col]);
                if( rowAdd.size() == c ) {
                    ans.push_back(rowAdd);
                    rowAdd.clear();
                }
            }
        }
        return ans;
    }
};

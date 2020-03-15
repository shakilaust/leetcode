class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector < int > ans;
        int rows = matrix.size();
        int columns = matrix[0].size();
        for( int i = 0 ; i < rows ; i++ ) { 
            for( int j = 0 ; j < columns ; j++ ) { 
                
                int now = matrix[i][j];
                int mn = now;
                int mx = now;
                for( int k = 0 ; k < columns ; k++ ) { 
                    mn = min(matrix[i][k], mn );
                }
                
                for( int k = 0 ; k < rows ; k++ ) { 

                    mx = max(mx, matrix[k][j]);
                }
                
                if( now == mx && now == mn )  {
                ans.push_back(now);

                }

            }
        }
        return ans;
    }
};

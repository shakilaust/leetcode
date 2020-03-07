class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int ans = -1;
        int rows = mat.size();
        int columns = mat[0].size();
        for( int i = 0 ; i < columns && ans == -1 ; i++ ) { 

            int lookFor = mat[0][i];
            bool found = true;
            for( int j = 1 ; j < rows && found ; j++ ) { 
                int up = upper_bound(mat[j].begin(), mat[j].end(), lookFor) - mat[j].begin();
                int low = lower_bound(mat[j].begin(), mat[j].end(), lookFor) - mat[j].begin();
                if( up == low ) found = false;
            }
            
            if( found ) ans = lookFor;
        }
        return ans;
    }
};

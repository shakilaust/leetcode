const int NX = 200;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if( rows == 0 ) return 0;
        const int cols = matrix[0].size();
        int sumMatrix[NX + 1][ NX + 1] = {0};
        
        for( int i = 1 ; i <= rows ; i++ ) {
            for( int j = 1 ; j <= cols ; j++ ) {
                if( matrix[i-1][j-1] - '0' > 0 ) {
                    sumMatrix[i][j] = sumMatrix[i-1][j] + 1;
                }
            }
        }
        
        
        int ans = 0;
        
        for(int row = 1; row <= rows; row++ ) {
            
            int lft[ NX + 1 ] = {0};
            int rgt[ NX + 1 ] = {0};
            stack < int > st;
            for( int col = 1; col <= cols; col++ ) {
                while( !st.empty() && ( sumMatrix[row][col] <= sumMatrix[row][st.top()]) ) {
                    st.pop();
                }
                lft[col] = st.empty() ? 1 : st.top() + 1;
               
                st.push(col);
            }
            
            while( !st.empty() ) st.pop();
            
            for( int col = cols ; col >= 1; col-- ) {
                while( !st.empty() && (sumMatrix[row][col] <= sumMatrix[row][st.top()])) {
                    st.pop();
                }
                rgt[col] = st.empty() ? cols : st.top() - 1 ;
               
                int tmp = sumMatrix[row][col] * ( rgt[col] - lft[col] + 1 );
                if( tmp > ans ) {
                    ans = tmp;
                 }
                 st.push(col);
            }
        }
        
        
        
        return ans;
    }
};

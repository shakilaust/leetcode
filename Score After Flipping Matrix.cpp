class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {

        int column = A[0].size();
        int row = A.size();
        for( int i = 0 ; i < row ; i++ ) {
            if( !A[i][0]) for( int j = 0 ; j < column ; j++ ) A[i][j] = !A[i][j];
        }
        int ans = 0;
        for( int i = 0 ; i < column ; i++ ) {
            int ones = 0, zeros = 0;
            for( int j = 0 ; j < row ; j++ ) 
                if( A[j][i] == 0 ) zeros++;
                else ones++;
          //  cout << " i " << i << " max " << max(zeros, ones) << " val " << ( 1 << ( column - i  ) - 1)  ;
            int mx = max( zeros, ones );
            int add = ( mx * ( 1 << ( column - i  ) - 1));
            ans += add;
        }

        return ans;

    
        
    }
};

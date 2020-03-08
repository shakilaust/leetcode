class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if( rows == 0 ) { 
            return 0;
        }
        int columns = matrix[0].size();
        vector < vector < int > > add( rows + 1 , vector < int > ( columns + 1 , 0 ) );
        
        for( int i = 1 ; i <= rows ; i++ ) { 

            for( int j = 1 ; j <= columns ; j++ ) { 
                
                add[i][j] = ( add[i-1][j] + add[i][j-1] - add[i-1][j-1] ) + ( matrix[i-1][j-1] == '1' ? 1 : 0 );
                
            }
            cout << endl;
        }

        int ans = 0;
        
        for( int i = 1 ; i <= rows; i++ ) { 
            for( int j = 1 ; j <= columns ; j++ ) { 
                
                bool square = true;
                for( int k = 0 ; i - k >= 1 && j - k >= 1  && square ; k++ ) { 
                    
                    int sum = add[i][j] + add[i-1-k][j-1-k] - ( add[i][j-1-k] + add[i-1-k][j] );
                  
                    if( sum != ( k + 1 ) * ( k + 1 ) ) {
                        square = false;
                    }
                    
                    if(square) { 
                        ans = max( ans, sum );
                    }
                }
            }

        }
        return ans;
        
    }
};

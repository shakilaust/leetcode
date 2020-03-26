const int INF = 1e9 + 7;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int dx[] = {-1, -1, -1};
        int dy[] = {-1, 0, 1};
        int rows = A.size();
        int columns = A[0].size();
        for( int row = 0; row < rows ; row++ ) { 

            for( int column = 0; column < columns ; column++ ) { 

                int mn = INF;
                for( int i = 0 ; i < 3 ; i++ ) { 
                    int prvRow = row + dx[i];
                    int prvColumn = column + dy[i];
                    if( prvRow >= 0 && prvColumn >= 0 && prvColumn < columns ) { 
                        mn = min( mn, A[prvRow][prvColumn] );
                    }
                }
                
                A[row][column] += ( mn == INF ? 0 : mn );
               // cout << " row " << row << " column "
            }
        }
        
        int ans = INF;
        for( int column = 0 ; column < columns ; column++ ) { 
            ans = min( ans, A[rows-1][column]);
        }
        
        return ans;
    }
};

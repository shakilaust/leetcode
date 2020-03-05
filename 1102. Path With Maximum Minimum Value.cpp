class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int row = A.size();
        int column = A[0].size();
        vector < vector < bool > > visit( row + 1 , vector < bool > ( column + 1 , false ) );
        priority_queue < pair < int, pair< int , int > > > pq;
        
        pq.push( make_pair( A[0][0], make_pair( 0 , 0 ) ) );
        int ans = -1;
        while( !pq.empty()) {
            pair< int, pair< int, int> > now = pq.top();
            pq.pop();
            int x = now.second.first;
            int y = now.second.second;
            if( visit[x][y] ) { 
                continue;
            }
            visit[x][y] = true;
            if( x == row - 1 && y == column -1 ) { 
                ans = now.first;
                break;
            }
            int dx[] = {1, -1, 0, 0 };
            int dy[] = {0, 0, 1, -1 };
            for( int i = 0 ; i < 4 ; i++ ) { 

                int nx = x + dx[i];
                int ny = y + dy[i];
                if( nx >= 0 && nx < row && ny >= 0 && ny < column && visit[nx][ny] == false ) { 
                    pq.push( make_pair( min( now.first, A[nx][ny] ), make_pair( nx, ny)));
                }
            }

        }
        
        return ans;
    
    }
};

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        if(rooms.size() == 0) return;
        
        int rows = rooms.size();
        int columns = rooms[0].size();
        
        vector < vector < bool > > vis( rows + 1 , vector < bool > ( columns + 1 , false ) );

        queue < pair < int, int > > q;
        queue < int > cost;
        for( int row = 0 ; row < rows ; row++ ) { 
            for( int column = 0 ; column < columns ; column++ ) { 
                if(rooms[row][column] > 0 ) continue;
                if(rooms[row][column] == 0 ) {

                    q.push( make_pair(row, column));
                    cost.push(0);
                }
                vis[row][column] = true;
                
            }
        }

        while(!q.empty()) { 
            pair < int, int > grid = q.front();
            q.pop();
            int x = grid.first;
            int y = grid.second;
            int currentCost = cost.front();
            cost.pop();
            
            for( int i = 0 ; i < 4 ; i++ ) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if( nx >= 0 && nx < rows && ny >= 0 && ny < columns && vis[nx][ny] == false ) {
                    q.push({nx, ny});
                    vis[nx][ny] = 1;
                    cost.push(currentCost + 1 );
                    rooms[nx][ny] = currentCost + 1;
                }
            }
            

        }
    }
};

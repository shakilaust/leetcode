int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
class Solution {

int rows = 0;
int columns = 0;

int bfs( pair< int, int > from, pair< int, int > to, vector<vector<int>>& forest) {

        queue < pair< int, int > > q;
        queue < int > cost;
        q.push(from);
        cost.push(0);
        vector< vector< int > > visit( rows, vector < int > ( columns , 0 ) );
    
        visit[from.first][from.second] = 1;
     
        
        while(!q.empty()){ 

            pair< int, int > now = q.front();
            q.pop();
            int prvCost = cost.front();
            cost.pop();
            if( to == now ) { 
                return prvCost;
            }
            for( int i = 0 ; i < 4 ; i++ ) { 

                int nx = dx[i] + now.first;
                int ny = dy[i] + now.second;
                
                if( nx < 0 || nx >= rows || ny < 0 || ny >= columns || forest[nx][ny] == 0 ) continue;
                if(visit[nx][ny] == 1 ) continue;
                visit[nx][ny] = 1;
                cost.push( prvCost + 1 );
                q.push({nx, ny});
            }
            
        }
    
    return -1;
        
}
public:
    int cutOffTree(vector<vector<int>>& forest) {
        
        priority_queue< pair< int, pair< int, int > >, vector < pair< int, pair< int, int > >>, greater< pair< int, pair< int, int > >> > pq;
        rows = forest.size();
        columns = forest[0].size();
        
        for( int row = 0 ; row < rows ; row++ ) { 
            for( int col = 0 ; col < columns; col++ ) { 
                if(forest[row][col] > 1 ) { 
                    pq.push({ forest[row][col], {row, col}});
                }
            }

        }
        
        pair< int, int > prv;
        prv = {0,0};
        int ans = 0;
        while( !pq.empty()) { 
            int tmp = bfs(prv, pq.top().second, forest);
         //   cout << " here " << prv.first << " " << prv.second << " to " << pq.top().second.first << " " << pq.top().second.second << "  need: " << tmp << endl;
            if( tmp == -1 ) return -1;
            ans += tmp;
            prv = pq.top().second;
            pq.pop();
        }
        
        return ans;
        
        
        
    }
};

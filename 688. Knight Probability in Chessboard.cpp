int dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };
map < pair< pair<int,int>, int>, bool > vis;
map < pair< pair<int,int>, int>, double > dp;
double dfs(int N, int K, int x, int y) { 
 
       if( K == 0 ) return 1.00;
       if(vis.find(make_pair( make_pair(x, y), K )) != vis.end()) { 
            return dp[make_pair( make_pair(x, y), K)];
       }
        vis[make_pair( make_pair(x, y), K)] = true;
        double res = 0;
        for( int i = 0 ; i < 8 ; i++ ) { 
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N ) { 
                res += dfs( N, K - 1 , nx, ny );
            }
        }
       
        return dp[make_pair( make_pair(x, y), K)] = res / 8.0;
    
}

class Solution {
public:
    

  
    double knightProbability(int N, int K, int r, int c) {
        
        vis.clear();
        dp.clear();
        return dfs( N , K , r , c );
    }
};

const int NX = 1e5 + 10;

vector < int > graph[ NX ];
bool hasFruit[ NX ];

class Solution {
public:
    
    pair < int, bool > dfs( int current, int parent) {
        bool found = false;
        int cost = 0;
        for( int nx: graph[current] ) {
            if( nx == parent ) continue;
            auto now = dfs( nx, current );
            if( now.second ) {
                found = true;
                cost += now.first + 2;
            }
        }
        
        found = found || hasFruit[current];
        
        return { cost, found };
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for( int i = 0 ; i < n ; i++ ) {
            hasFruit[i] = hasApple[i];
            graph[i].clear();
        }
    
        for( int i = 0 ; i < edges.size() ; i++ ) {
            int x = edges[i][0];
            int y = edges[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
        auto ans = dfs( 0 , -1 );
        return ans.first;
    }
};

class Solution {
public:
    vector < vector < int > > graph;
    vector < int > vis;
    
    void dfs( int x ) { 

        vis[x] = 1;
        int sz = graph[x].size();
        for( int i = 0 ; i < sz ; i++ ) { 
            if( vis[graph[x][i]] == 0 ) dfs( graph[x][i] );

        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        for( int i = 0 ; i < n ; i++ ) { 
            vis.push_back(0);
            vector < int > dummy;
            for( int j = 0 ; j < n ; j++ ) { 
                if(i != j && M[i][j] == 1 ) {
                   dummy.push_back(j);
                }
            }
            graph.push_back(dummy);
        }
        
        int ans = 0;

        for( int i = 0 ; i < n ; i++ ) { 
            if( vis[i] == 0 ) { 
                dfs( i );
                ans++;
            }
        } 
        return ans;
    }
};

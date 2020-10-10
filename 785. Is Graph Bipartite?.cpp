class Solution {
public:
    vector < int > visits;
    bool dfs(int idx,int col, vector<vector<int>>& graph ) { 
        int sz = graph[idx].size();
        visits[idx] = col;
        bool ok = true;
        for( int nxt: graph[idx] ) {
            if( visits[nxt] == 0 ) ok = dfs( nxt, 3 - col , graph );
            else if( visits[nxt] == col ) {
                ok = false;
            }
            if( ok == false ) break;
        }
        return ok;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int sz = graph.size();
        visits.resize(sz, 0 );
        for( int i = 0 ; i < sz ; i++ ) { 
            if( visits[i] == 0 ) { 
                if( dfs( i , 1 , graph ) == false ) return false;
            }
        }
        
        return true;
    }
};

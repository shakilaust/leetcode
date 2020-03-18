class Solution {
public:
    
    void dfs(int node, vector<vector<int>>& graph, vector< bool > &vis) { 
        vis[node] = true;
        for( int i = 0 ; i < graph[node].size() ; i++ ) { 
            int nxtNode = graph[node][i];
            if(vis[nxtNode] == false ) dfs( nxtNode, graph, vis );
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int sz = rooms.size();
        vector < bool > vis( sz , false );
        dfs( 0 , rooms , vis );
        for( int i = 0 ; i < sz ; i++ ) { 
            if( vis[i] == false ) return false;
        }
        return true;
    }
};

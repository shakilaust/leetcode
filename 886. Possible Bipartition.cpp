class Solution {
    
vector < int > color;
vector < vector < int > > graph;
    
bool dfs( int node,  int col ) { 
    
        color[node] = col;
        int sz = graph[node].size();
        for( int i = 0 ; i < sz ; i++ ) { 
            int nxtNode = graph[node][i];
            if( color[nxtNode] == 0 ) { 
                bool get = dfs(nxtNode, 3 - col );
                if( get == false ) return get;
            } else if( color[ nxtNode ] == col ) return false;
        }
    
        return true;

}
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        color.resize( N + 1 , 0 );
        graph.resize( N + 1 );
        for( int i = 0 ; i < dislikes.size() ; i++ ) { 
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
        }
        
        
        return dfs(1 , 1 );
        
        
    }
};

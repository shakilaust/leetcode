class Solution {
public:
    void dfs(int node, int endNode, vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &vis, vector<int> &currentTrack) {        
        
        vis[node] = 1;
        currentTrack.push_back(node);
        if( node == endNode ) { 
            ans.push_back(currentTrack);
            vis[endNode] = 0;
            if(currentTrack.size() > 0 ) { 
                currentTrack.pop_back(); // remove n - 1 node;
            }
            return;
        }
      
        
          
        for( int i = 0 ; i < graph[node].size() ; i++ ) { 
            int nxtNode = graph[node][i];
            if( vis[nxtNode] == 0 ) { 
                dfs(nxtNode, endNode, graph, ans, vis, currentTrack);
            }
        }
        vis[node] = 0;
        if(currentTrack.size() > 0 ) {
            currentTrack.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int sz = graph.size();
        int endNode = sz - 1;
        vector< vector<int> > ans;
        vector < int > vis( sz ), currentTrack;
      
         if(endNode < 0 ) { 
            return ans;
        }
        dfs(0, endNode, graph, ans, vis, currentTrack);
        return ans;
    }
};

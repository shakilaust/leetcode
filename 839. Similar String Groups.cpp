vector < vector < int > > graph;
vector < bool > visited;


class Solution {
public:
    int n;
    
    void ini() {
        graph.resize(n);
        visited.resize(n);
       
        for( int i = 0 ; i < n ; i++ ) {
            visited[i] = false;
            graph[i].clear();
        }
    }
    
    void dfs( int x ) {
        visited[x] = true;
        for( int nx: graph[x] ) {
            if( visited[nx] == false ) {
                dfs( nx );
            }
        }
    }
    
    
    bool isEdge( string &a, string &b) {
        int cnt = 0;
        for( int i = 0 ; i < a.size() && cnt <= 2; i++ ) {
            if( a[i] != b[i] ) {
                cnt++;
            }
        }
        return cnt <= 2;
        
    }
    
    
    
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        ini();
        int idx = 0;
        ini();
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ) {
            for( int j = i + 1; j < n ; j++ ) {
                if( isEdge( strs[i], strs[j] ) ) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        for( int i = 0 ; i < n ; i++ ) {
            if( visited[i] == false ) {
                dfs( i );
                ans++;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector < int > graph[ 2005 ];
    int vis[ 2005 ];
    
    void dfs( int x ) { 
        
        vis[x] = 1;
        int sz = graph[x].size();
        for( int i = 0 ; i < sz ; i++ ) { 
            if( vis[graph[x][i]] == 0 ) dfs( graph[x][i] );
        }

    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        
        if(words1.size() != words2.size() ) { 
            return false;
        }
        int node = 0;
        int sz = pairs.size();
        unordered_map < string, int > Idx;
        for( int i = 0 ; i < 2005; i++) { 
            graph[i].clear();
            vis[i] = 0;
        }
        
        for( int i = 0 ; i < sz ; i++ ) { 
            string a = pairs[i][0];
            string b = pairs[i][1];
            if( Idx.find(a) == Idx.end() ) Idx[a] = ++node;
            if( Idx.find(b) == Idx.end() ) Idx[b] = ++node;
            int x = Idx[a];
            int y = Idx[b];
            graph[x].push_back(y);
            graph[y].push_back(x);
            
        }
        
        int sz1 = words1.size();
        int sz2 = words2.size();
        for( int i = 0 ; i < sz1 ; i++ ) { 
            if( Idx.find(words1[i]) == Idx.end() ) Idx[words1[i]] = ++node;
            
        }
        
        for( int i = 0 ; i < sz2 ; i++ ) { 
            if(Idx.find(words2[i]) == Idx.end() ) return false;
        }
        
        
        
    
        for( int i = 0 ; i < sz1 ; i++ ) { 
            int x = Idx[words1[i]];
            int y = Idx[words2[i]];
            if( vis[x] == 0 ) dfs(x);
            if(vis[y] == 0 ) return false;
        }
        return true;
    }
};

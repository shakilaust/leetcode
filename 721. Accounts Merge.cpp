vector < vector < int > > graph;
vector < int > colors;




void dfs( int node, int c ) {
    colors[node] = c;
    for( int x: graph[node] ) {
        if( colors[x]  == 0 ) dfs( x, c );
    }
}
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int total = accounts.size();
        graph.resize( total + 1);
        colors.resize( total + 1, 0 );
        for( int i = 0 ; i < total + 1; i++ ) {
            graph[i].clear();
            colors[i] = 0;
        }
        
        unordered_map < string, vector < int > > sv;
        map < pair< int, int >, bool > connection;
        
        for( int i = 0 ; i < total ; i++ ) {
            int sz = accounts[i].size();
            for( int j = 1 ; j < sz ; j++ ) {
                if( sv[accounts[i][j]].size() > 0 ) {
                    for( int nxt: sv[accounts[i][j]] ) {
                        if( connection[{i, nxt}] == true ) continue;
                        connection[{i, nxt}] = true;
                        graph[i].push_back(nxt);
                        graph[nxt].push_back(i);
                    }
                }
                
                 sv[accounts[i][j]].push_back(i);
            }
        }
        
        int col = 0; 
        
        for( int i = 0 ; i < total ; i++ ) {
            if( colors[i] == 0 ) {
                dfs( i , ++col );
            }
        }
        vector < vector < string > > ans;
        for( int i = 1 ; i <= col ; i++ ) {
            string name = "";
            set < string > entries;
            for( int j = 0 ; j < total ; j++ ) {
                if( colors[j] != i ) continue;
                name = accounts[j][0];
                int sz = accounts[j].size();
                for( int k = 1 ; k < sz ; k++ ) {
                    entries.insert( accounts[j][k] );
                }
            }
            
            vector < string > res;
            res.push_back(name);
            
            for( string email: entries ) {
                res.push_back(email);
            }
            ans.push_back(res);
        }
        return ans;
    }
};

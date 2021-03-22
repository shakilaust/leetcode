class Solution {
public:
    unordered_map < string, bool > visited;
    string sourceNode;
    string targetNode;
    
    map < string, map< string, double > > graph;
    
    
    double dfs( string curNode, double mulValue) {
        
        if( curNode == targetNode ) {
            return mulValue;
        }
        
        double res = -1;
        for( auto now: graph[curNode] ) {
            string nxtNode = now.first;
            if( visited[nxtNode] == true ) continue;
            visited[nxtNode] = true;
            res = dfs( nxtNode , mulValue * now.second );
            visited[nxtNode] = false;
            if( res != -1 ) return res;
        }
        return res;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map < string, double > dummy;
        int sz = equations.size();
        for( int i = 0 ; i < sz ; i++ ) {
            string divided = equations[i][0];
            string divisor = equations[i][1];
            double quotient = values[i];
            if( graph.find( divided ) == graph.end() ) {
                graph.insert(  make_pair( divided, dummy ) );
            }
            if( graph.find( divisor ) == graph.end() ) {
                graph.insert( make_pair( divisor, dummy ) );
            }
            graph[divisor].insert( make_pair( divided , 1.0 / quotient ) );
            graph[divided].insert( make_pair( divisor, quotient ) );
        }
        vector < double > results;
        for( vector<string> query: queries) {
            sourceNode = query[0];
            targetNode = query[1];
            if( graph.find(sourceNode) == graph.end() || graph.find(targetNode) == graph.end() ) {
                results.push_back(-1);
            } else {
                visited[sourceNode] = true;
                results.push_back( dfs(sourceNode,1 ));
                visited[sourceNode] = false;
            }
        }
        
        return results;
    }
};

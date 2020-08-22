class Solution {
    
vector < bool > visit;
vector < vector < int > > graph;
vector < int > group;
    
    
  void dfs( int curNode) { 
        visit[curNode] = true;
        group.push_back(curNode);
        for( int nextNode: graph[curNode]) {
            if( visit[nextNode] == false ) dfs( nextNode );
        }
   }
    
    
public:
    void setGraph(vector<vector<int>>& pairs) { 
        for( int i = 0 ; i < pairs.size() ; i++ ) { 
            int x = pairs[i][0];
            int y = pairs[i][1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
    }
    
    void updateSortedGroup(string &s) { 
        string newString = "";
        
        for( int i = 0 ; i < group.size() ; i++ ) { 
            newString += s[group[i]];
        //    cout << " now " << group[i] << endl;
        }
        sort( newString.begin(), newString.end());
        sort(group.begin(), group.end());
      //  cout << " newString " << newString << endl;
        for( int i = 0 ; i < group.size() ; i++ ) { 
            s[group[i]] = newString[i];
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
         int n = s.size();
         visit.resize(n, false);
         graph.clear();
         graph.resize(n);
         setGraph(pairs);
         
         for( int i = 0 ; i < n ; i++ ) { 
            if( visit[i] == false && graph[i].size() > 0 ) { 
                group.clear();
                dfs(i);
                updateSortedGroup(s);
            }
        }
        
        return s;
        
        
    
    }
};

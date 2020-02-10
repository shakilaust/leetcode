class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector < int > inDegree(numCourses + 1 , 0 );
        vector < vector < int > > graph( numCourses + 1 );
        int sz = pre.size();
        for( int i = 0 ; i < sz ; i++ ) { 
                int y = pre[i][0];
                int x = pre[i][1];
                inDegree[y]++;
                graph[x].push_back(y);
            
        }
        
        queue < int > q;
        
        for( int i = 0 ; i < numCourses ; i++ ) { 
            if( inDegree[i] == 0 ) { 
                q.push(i);
            }
        }
        
        vector<int> ans;
        int takenCourses = 0;
        while( !q.empty() ) { 
            int sub = q.front();
            takenCourses++;
            q.pop();
            ans.push_back(sub);
            int sz = graph[sub].size();
            for( int i = 0 ; i < sz ; i++ ) {
                int after = graph[sub][i];
                inDegree[after]--;
                if( inDegree[after] == 0 ) q.push(after);

            }
        }
        
        if( takenCourses != numCourses ) ans.clear();
        
        return ans;
    }
};

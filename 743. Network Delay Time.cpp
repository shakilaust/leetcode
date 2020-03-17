class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector < int > dis( N + 1 , -1 );
        vector < bool > vis( N + 1 , false );
        
        vector < vector < int > > graph( N + 1);
        vector < vector < int > > cost( N + 1);
        
        for( int i = 0 ; i < times.size() ; i++ ) { 

            graph[times[i][0]].push_back(times[i][1]);
            cost[times[i][0]].push_back(times[i][2]);
        }
                                       
        dis[K] = 0;
        priority_queue< pair< int, int > > pq;
        pq.push(make_pair(0, K));
                                       
        
        
        while(!pq.empty()) { 
            
            int currentCost = pq.top().first * -1;
            int currentNode = pq.top().second;
            pq.pop();
            vis[currentNode] = true;
            for( int i = 0 ; i < graph[currentNode].size() ; i++  ) {
                
                int nxtNode = graph[currentNode][i];
                
                if( vis[nxtNode] == true ) continue;
                int nxtCost = dis[currentNode] + cost[currentNode][i];
               
                if( dis[nxtNode] == -1 || dis[nxtNode] > nxtCost ) { 
                   
                    dis[nxtNode] = nxtCost;
                    pq.push(make_pair(nxtCost * -1 , nxtNode ) );
                }

            }

        }
        
        
        int ans = -1;
        for( int i = 1 ; i <= N ; i++ ) { 
            if(dis[i] == -1 ) return -1;
            if( ans == -1 || ans < dis[i] ) ans = dis[i];
        }
        return ans;
    }
};

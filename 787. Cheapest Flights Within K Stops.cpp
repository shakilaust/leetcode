class Solution {
    using PII = pair < int , int >;
    using TII = tuple < int, int, int >;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector< vector<PII> > graph( n, vector<PII>());
      
        priority_queue< TII, vector<TII>, greater<>> pq;
        for( vector< int > flight: flights) { 
            graph[flight[0]].push_back({flight[1], flight[2]});
        }
        pq.push({0, src, 0});
        
        while(!pq.empty()) { 
            auto [cost, curIdx, distance] = pq.top();
             if (curIdx == dst) return cost;
             pq.pop();
            for( auto [neightbourIdx, pathCost]: graph[curIdx]) { 
                if(distance <= K ) { 
                    pq.push({pathCost + cost, neightbourIdx, distance + 1 });
                }
            }

        }
        
        return -1;

        
    }
};

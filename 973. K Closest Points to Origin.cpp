class Solution {
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        
        priority_queue < pair< int, pair< int, int > > > pq;
        
        
        
        vector < vector< int > > ans;
        
        int sz = points.size();
        
        for( int i = 0 ; i < sz ; i++ ) { 
            
            int dis = ( points[i][0] * points[i][0] ) + ( points[i][1] * points[i][1]);
            if( pq.size() < K ) pq.push( make_pair( dis, make_pair( points[i][0], points[i][1])));
            else {
                if( pq.top().first > dis ) { 
                    pq.pop();
                    pq.push( make_pair( dis, make_pair( points[i][0], points[i][1])));
                }
            }
            
            

        }

        while(!pq.empty()){ 
            ans.push_back( {pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue< int, vector< int >,  greater<int>> pq;
        int ans = 0;
        for( int i = 0 ; i < sticks.size() ; i++ ) { 
            pq.push(sticks[i]);
        }
        
        while( pq.size() > 1 ) { 
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            pq.push( x + y );
            ans += ( x + y );
        }
        
        return ans;
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue < int, vector < int >, greater < int > > pq;
        int mx = -1;
        set < int > inp;
        for( int x: nums ) inp.insert( x );
        for( int x: inp ) {
            if( pq.size() < 3 ) {
                if( pq.empty() ) mx = x;
                else mx = max( mx, x );
                pq.push( x );
            }
            else {
                if( pq.top() < x ) {
                    pq.pop();
                    pq.push( x );
                }
            }
        }
        
        return pq.size() == 3 ? pq.top() : mx;
    }
};

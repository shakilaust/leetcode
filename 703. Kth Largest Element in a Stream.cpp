class KthLargest {
    
public:
    priority_queue < int, vector< int > , greater<int> > pq;
    int lim;
    KthLargest(int k, vector<int>& nums) {
        lim = k;
        for( int x: nums ) { 
            if( pq.size() < k ) pq.push( x );
            else { 
                if( pq.top() < x ) { 
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }
    
    int add(int val) {
        if( pq.size() < lim ) pq.push( val );
        else {
            if( pq.top() < val ) { 
                pq.pop();
                pq.push(val);
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

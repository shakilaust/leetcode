class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       
        priority_queue< int, vector<int>, greater<int> > pq;
        
        int sz = nums.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            
            if(pq.size() < k ) pq.push(nums[i]);
            else {

                if(pq.top() < nums[i] ) { 

                    pq.pop();
                    pq.push(nums[i]);
                }
            }

        }
        
        
        return pq.top();
    }
};

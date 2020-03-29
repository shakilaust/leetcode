class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector < int > sum( n + 1 , 0 );
        
        int ans = n + 1;
        for( int i = 0 ; i < n ; i++ ) { 
            sum[i+1] = sum[i] + A[i];
        }

        deque < int > dq;
        for( int i = 0 ; i <= n ; i++ ) { 

            while( !dq.empty() && sum[i] <= sum[dq.back()] ) dq.pop_back();
            while( !dq.empty() && sum[i] >= sum[dq.front()] + K ) {
                ans = min( ans , i - dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
        }
        
        return ans < n + 1 ? ans : -1;
    }
};

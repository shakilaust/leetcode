class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int sz = A.size();
        vector < int > ans( sz , 0 );
        int low = 0, high = sz - 1;
        while( low <= high ) { 
            int lowSqr = A[low] * A[low];
            int highSqr = A[high] * A[high];
            if( highSqr >= lowSqr ) { 
                ans[--sz] = highSqr;
                high--;
            } else { 
                ans[--sz] = lowSqr;
                low++;
            }
        }
        
        return ans;
    }
};

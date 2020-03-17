class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const long int mod = 1e9 + 7 ;
        long int arrsum = 0, postsum = 0, presum = 0, currentsum = 0, mxsum = 0;
        for( auto val: arr) { 
            arrsum += val;
            presum = max(presum, arrsum );
            currentsum += val;
            mxsum = max(currentsum, mxsum);
            currentsum = currentsum < 0 ? 0 : currentsum;
        }
        
        currentsum = 0;
        for( int i = arr.size() - 1 ; i >= 0 ; i-- ) { 
            currentsum += arr[i];
            postsum = max(postsum, currentsum);
        }
        long int ans = 0;
        if( k == 1 ) return mxsum;
        else if( arrsum > 0 && k > 2 ) { 
            ans = postsum + (arrsum * ( k - 2 ) ) + presum;
        }  else { 
            ans = max(mxsum, presum  + postsum );
        }
        
        return ans % mod;
    }
};

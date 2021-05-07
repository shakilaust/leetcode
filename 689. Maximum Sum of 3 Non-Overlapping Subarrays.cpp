class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector < int > windowSum;
        int curSum = 0;
        for( int i = 0 ; i < nums.size() ; i++ ) {
            curSum += nums[i];
            if( i >= k ) {
                curSum -= nums[i-k];
            }
            if( i >= k - 1 ) {
                windowSum.push_back(curSum);
            }
            
        }
        vector < int > lft( windowSum.size() );
        vector < int > rgt( windowSum.size() );
        
        int best = 0;
        for( int i = 0 ; i < windowSum.size() ; i++ ) {
            if( windowSum[i] > windowSum[best] ) {
                best = i;
            }
            lft[i] = best;
        }
        best = windowSum.size() - 1;
        for( int i = best ; i >= 0 ; i-- ) {
            if( windowSum[i] >= windowSum[best] ) {
                best = i;
            }
            rgt[i] = best;
        }
        vector < int > ans({-1, -1, -1} );
        
        for( int j = k ; j < windowSum.size() - k ; j++ ) {
            int i = lft[j-k];
            int l = rgt[j+k];
            
            if( ans[0] == -1 || windowSum[ans[0]] + windowSum[ans[1]] + windowSum[ans[2]] < windowSum[i] + windowSum[j] + windowSum[l] ) {
                ans[0] = i;
                ans[1] = j;
                ans[2] = l;
            }
            
        }
        
        return ans;
    }
};

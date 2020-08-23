class Solution {
public:
    int divisorValue( vector < int > &nums, int d ) { 
        int sum = 0;
        for( int num: nums) { 
            if( num % d == 0 ) sum += ( num / d );
            else sum += ( num / d ) + 1;
        }
        
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low = 1, high = INT_MAX, ans = -1;
        while( low <= high ) { 
            int mid = low + ( high - low ) / 2;
            int sum = divisorValue( nums, mid );
            if( sum <= threshold ) { 
                ans = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        
        return ans;
    }
};

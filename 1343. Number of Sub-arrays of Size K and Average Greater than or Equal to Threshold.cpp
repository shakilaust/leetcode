class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sz = arr.size();
        int sum = 0, low = 0;
        int ans = 0;
        for( int i = 0 ; i < sz ; i++ ) {
            sum += arr[i];
            if( i - low + 1 == k ) {
                if( sum / k >= threshold ) ans++;
                sum -= arr[low++];
            }
        }
        
        return ans;
    }
};

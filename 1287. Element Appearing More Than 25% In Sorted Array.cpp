class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int sz = arr.size();
        
        int freq = 1, ans = arr[0];
        int mxFreq = 1;
        
        for( int i = 1 ; i < sz ; i++ ) {
            if( arr[i] == arr[i-1] ) {
                freq++;
            } else freq = 1;
            if( freq > mxFreq ) {
               ans = arr[i];
               mxFreq = freq;
            }
        }
        return ans;
        
    }
};

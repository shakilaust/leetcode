class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        unordered_map < int, int > freq, saveAns;
        int sz = nums.size();
        vector < int > ans( sz , 0 );
        int sum = 0;
        int cnt = 1;
        for( int i = sz - 2 ; i >= 0 ; i-- ) {
            int diff = ( nums[i+1] - nums[i] );
            ans[i] += ( diff * cnt ) + sum;
            cnt++;
            sum = ans[i];
        }
        
        cnt = 1;
        sum = 0;
        for( int i = 1 ; i < sz ; i++ ) {
            int diff = ( nums[i] - nums[i-1]);
            int sv = ( diff * cnt ) + sum;
            ans[i] += sv;
            cnt++;
            sum = sv;
        }
               
       
        return ans;
    }
};

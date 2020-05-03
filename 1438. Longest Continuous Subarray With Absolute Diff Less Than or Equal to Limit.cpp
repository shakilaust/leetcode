class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset < int > sv;
        
        
        int low = 0, ans = 0;
        for( int i = 0 ; i < nums.size(); i++ ) { 
            sv.insert(nums[i]);
            auto mn = sv.begin();
            auto mx = sv.end();
            mx--;
            while( low <= i &&  *mx - *mn > limit ) { 
                sv.erase(sv.find(nums[low++]));
                mn = sv.begin();
                mx = sv.end();
                mx--;
                
               

            }
            ans = max( ans, i - low + 1 );
            
        }
        return ans;
        
    }
};

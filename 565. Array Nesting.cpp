class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int sz = nums.size();
        if( sz == 0 ) return 0;
        vector < int > vis( sz + 1 , 0 );
        int ans = 0;
        for( int i = 0 ; i < sz ; i++ ) { 
            int idx = nums[i];
            int cnt = 1;
            while( nums[idx] != nums[i] ) { 
                if( vis[nums[idx]] == 0 ) { 
                    cnt++;
                    vis[nums[idx]] = 1;
                    idx = nums[idx];

                } else break; // previously found

            }
            
            ans = max( ans, cnt );

        }
        return ans;
    }
};

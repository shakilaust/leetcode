class Solution {
public:
    vector < vector < int > > ans;
    void generate( int left, vector < int> &nums, vector < int > current ,  vector < int > vis ) { 
        if( left == 0 ) { 
            ans.push_back(current);
            return;
        }

        for( int i = 0 ; i < nums.size();  i++ ) { 
            if( vis[i] == 0 ) { 
                current.push_back(nums[i]);
                vis[i] = 1;
                generate(left - 1 , nums, current , vis );
                current.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        int sz = nums.size();
        vector < int > vis( sz, 0 ), cur;
        generate(sz , nums, cur, vis );
        return ans;
    }
};




void dfs(vector < int >&nums, set < vector < int > >&vis, vector < vector < int > > &ans, vector < int > &current, int target , int pos ) { 
    
        if( target == 0 ) { 
            if(vis.find(current) == vis.end()) { 
                vis.insert(current);
                ans.push_back(current);
                return;
            }
            return;
        }

        if( pos == nums.size() ) return;
     //   cout << " pos " << pos << " target " << target << endl;
        if( target - nums[pos] >= 0 ) { 
            current.push_back(nums[pos]);
            dfs(nums , vis, ans, current, target - nums[pos],  pos + 1 );
            current.pop_back();
        }
    
       dfs(nums, vis, ans, current, target , pos + 1 );
    
}
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set < vector < int > > vis;
        vector < vector < int > > ans;
        vector < int > current;
        dfs(nums, vis, ans, current, target , 0 );
        return ans;
    }
};

class Solution {
public:
    vector < vector < int > > ans;
    set < vector < int > > taken;
    void dfs( int start, vector < int > &nums, vector < int > &soFar, int lst) {
        if( start == nums.size() ) {
            if( soFar.size() > 1 && taken.find( soFar ) == taken.end() ) {
                ans.push_back( soFar );
                taken.insert( soFar );
            }
                
            return;
        }
        dfs( start + 1 , nums, soFar , lst );
        for( int i = start ; i < nums.size() ; i++ ) {
            if( nums[i] >= lst ) {
                soFar.push_back( nums[i] );
                dfs( i + 1 , nums, soFar, nums[i] );
                soFar.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector < int > soFar;
        ans.clear();
        taken.clear();
        dfs( 0 , nums, soFar, INT_MIN );
        return ans;
    }
};

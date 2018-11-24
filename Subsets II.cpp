class Solution {
public:
    void dfs( int lim, int pos, vector < int > cur , vector < int > &nums, vector < vector < int > > &answer ) { 
        if( lim == pos ) 
        {
            if(find(answer.begin(), answer.end() , cur ) == answer.end()) { 
                answer.push_back(cur);
            }
            
            return;
        }
        cur.push_back( nums[pos]);
        dfs(lim, pos + 1 , cur , nums , answer );
        cur.pop_back();
        dfs(lim, pos + 1 , cur , nums, answer );
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int lim = nums.size();
        vector < vector < int > > answer;
        vector < int > cur;
        sort( nums.begin(), nums.end());
        dfs(lim, 0, cur , nums, answer);
        return answer;
    }
};

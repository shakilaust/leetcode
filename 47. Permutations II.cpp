class Solution {
public:
    vector < vector < int > > ans;
    vector < bool > isTaken;
    set < vector < int > > isUnique;

    void dfs( int pos, int lim, vector < int > &nums, vector < int > &values) {
        if( pos == lim ) {
            if( isUnique.find( values ) == isUnique.end() ) {
                isUnique.insert( values );
                ans.push_back( values );
                return;
            }
        }
        
        for( int i = 0 ; i < lim ; i++ ) {
            if( isTaken[i] ) continue;
            values.push_back( nums[i] );
            isTaken[i] = true;
            dfs( pos + 1, lim , nums, values );
            values.pop_back();
            isTaken[i] = false;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        int lim = nums.size();
        isTaken.resize(lim, false);
        isUnique.clear();
        vector < int > values;
        dfs( 0 , lim, nums, values );
        return ans;
    }
};

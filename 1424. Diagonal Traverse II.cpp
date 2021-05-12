class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector < int > ans;
        unordered_map < int, vector< int > > m;
        int mx = 0;
        for( int row = 0 ; row < nums.size() ; row++ ) {
            for( int col = 0 ; col < nums[row].size(); col++ ) {
                m[ row + col].push_back(nums[row][col]);
                mx = max( mx, row + col );
            }
        }
        for( int key = 0 ; key <= mx ; key++ ) {
            for( auto x = m[key].rbegin(); x != m[key].rend(); x++ ) {
                ans.push_back(*x);
            }
        }
        
        return ans;
    }
};

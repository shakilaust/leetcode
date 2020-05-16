class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort( nums.begin(), nums.end() );
        vector < vector< int > > ans;
        int sz = nums.size();
        for( int i = 0 ; i < sz - 3 ; i++ ) {
            if( i && nums[i] == nums[i-1] ) continue;
            for( int j = i + 1 ; j < sz - 2 ; j++ ) {
                if( j > i + 1 && nums[j] == nums[j-1] ) continue;
                int x = nums[i];
                int y = nums[j];
                int low = j + 1;
                int high = sz - 1;
                while( low < high ) {
                    if( high < sz - 1 && nums[high] == nums[high + 1 ] ) high--;
                    else if( low > j + 1 && nums[low] == nums[low - 1 ] ) low++;
                    else if( x + y + nums[low] + nums[high] > target ) high--;
                    else if( x + y + nums[low] + nums[high] < target ) low++;
                    else {
                        ans.push_back({x, y, nums[low], nums[high]});
                        high--;
                        low++;
                    }
                        
                }

            }

        }
        return ans;
    }
};

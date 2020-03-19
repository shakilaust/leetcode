class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        set < pair< int, int > > ans;
        for( int i = 0 ; i < nums.size() ; i++ ) { 
            for( int j = i + 1 ; j < nums.size() ; j++ ) { 
                if( abs(nums[i] - nums[j]) == k ) { 
                    ans.insert(make_pair(nums[i], nums[j]));
                }
            }
        }
        return ans.size();
    }
};

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector < int > ans;
        for(int i = 1 ; i < nums.size() ; i += 2 ) { 
            int freq = nums[i-1];
            while( freq-- ) ans.push_back(nums[i]);
        }
        return ans;
    }
};

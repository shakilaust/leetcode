class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        unordered_map < int, int > cnt;
        vector < int > ans;
        for( int x: nums1 ) cnt[x]++;
        
        for( int x: nums2) { 
            if( cnt[x] > 0 ) { 
                ans.push_back(x);
                cnt[x] -= ( sz1 + sz2 );
            }   
        }
        
        return ans;
    }
};

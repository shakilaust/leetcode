class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map < int, int > one;
        int sz = nums1.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            one[nums1[i]]++;
        }
        vector < int > ans;
        sz = nums2.size();

        for( int i = 0 ; i < sz ; i++ ) { 
            if( one[nums2[i]] > 0 ) {
                one[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};

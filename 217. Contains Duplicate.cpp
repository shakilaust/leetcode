class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map < int, int > freq;
        for( int num: nums ) { 
            freq[num]++;
            if( freq[num] > 1 ) return true;
        }
        return false;
    }
};

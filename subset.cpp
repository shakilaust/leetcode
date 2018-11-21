class Solution {
public:
    vector < int > subset, inp;
    vector < vector<int> > answer;
    int limit;
    void allPossibleSets( int idx) {
        if(idx >= limit) {
            answer.push_back(subset);
            return;
        }
        allPossibleSets( idx+1);
        subset.push_back(inp[idx]);
        allPossibleSets(idx+1);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        limit = nums.size();
        for( int i = 0 ; i < limit ; i++ ) inp.push_back(nums[i]);
        allPossibleSets(0);
        return answer;
    }
};

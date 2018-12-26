class Solution {
public:
set < vector < int > > taken;
void generateAnswer( int curPos, int target, vector < int > &candidates, vector < int > soFar, vector < vector< int>> &ans) {
if( curPos >= candidates.size()) {
    if(target == 0 ) { 
        if(taken.find(soFar) == taken.end()) {
        ans.push_back(soFar);
        taken.insert(soFar);
        }

        return;
    }
    return;
    
}
    
    
    // nibo;
    if(target >= candidates[curPos]) {
        soFar.push_back(candidates[curPos]);
        generateAnswer(curPos, target - candidates[curPos], candidates, soFar, ans);
        generateAnswer(curPos + 1, target - candidates[curPos], candidates, soFar, ans);
        soFar.pop_back();
    }
        generateAnswer(curPos + 1, target , candidates, soFar, ans);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector < vector < int > > ans;
        vector < int > soFar;
        generateAnswer(0, target, candidates, soFar, ans);
        return ans;
    }

};

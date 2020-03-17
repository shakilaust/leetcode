class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int sz = groupSizes.size();
        vector<vector<int>>current( sz + 1);
        vector< vector< int > > ans;
        for( int i = 0 ; i < groupSizes.size() ; i++ ) { 
            current[groupSizes[i]].push_back(i);
            if( current[groupSizes[i]].size() == groupSizes[i]) { 
                ans.push_back(current[groupSizes[i]]);
                current[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};

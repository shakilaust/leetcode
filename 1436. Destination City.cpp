class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map< string, int> outGoing;
        set < string > ans;
        for( vector<string> path: paths) {
            if( outGoing[path[1]] == 0 ) {
                ans.insert(path[1]);
            }
            outGoing[path[0]]++;
            if( ans.find(path[0]) != ans.end() ) {
                ans.erase(path[0]);
            }
        }
        
        return *ans.begin();
    }
};

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int matchIdx = 0;
        if( ruleKey == "color" ) matchIdx = 1;
        else if( ruleKey == "name" ) matchIdx = 2;
        int ans = 0;
        for( int i = 0 ; i < items.size() ; i++ ) {
            if( ruleValue == items[i][matchIdx] ) {
                ans++;
            }
        }
        
        return ans;
    }
};

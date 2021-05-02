class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int sz = s.size();
        string ans = "";
        for( int i = 0 ; i < sz ; i++ ) {
            ans += 'a';
        }
        for( int i = 0 ; i < sz ; i++ ) {
            ans[indices[i]] = s[i];
        }
        return ans;
    }
};

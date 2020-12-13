class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map < char, bool > isOk;
        for( char s: allowed) {
            isOk[s] = true;
        }
        
        int ans = 0;
        for( string word: words) {
            bool ok = true;
            for( int i = 0 ; i < word.size() && ok ; i++ ) {
                if( isOk.find(word[i]) == isOk.end()) ok = false;
            }
            if( ok ) {
                ans++;
            }
        }
        
        return ans;
    }
};

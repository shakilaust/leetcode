class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);
        string word;
        vector < string > words;
        while( ss >> word ) {
            words.push_back(word);
        }
        if( pattern.size() != words.size() ) return false;
        unordered_map < char, string > umap;
        unordered_map < string, bool > taken;
        for( int i = 0 ; i < words.size() ; i++ ) {
            if( taken.find(words[i]) == taken.end() ) {
                if( umap.find(pattern[i]) != umap.end() ) return false;
                umap[pattern[i]] = words[i];
                taken[words[i]] = true;
            } else {
                if( umap.find(pattern[i]) == umap.end() ) return false;
                if( umap[pattern[i]] != words[i] ) return false;
            }
        }
        return true;
    }
};

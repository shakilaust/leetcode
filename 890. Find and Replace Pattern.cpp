class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector < string > res;
        
        for( string word: words) { 
        
            int psz = pattern.size();
            int wsz = word.size();
            if( psz != wsz ) continue;
            unordered_map < char, char > fromWord;
            unordered_map < char, char > fromPattern;
            
            bool ok = true;
            for( int i = 0 ; i < psz && ok; i++ ) { 
                if( fromWord.find(word[i]) == fromWord.end() && fromPattern.find(pattern[i]) == fromPattern.end()) { 
                    fromWord[word[i]] = pattern[i];
                    fromPattern[pattern[i]] = word[i];
                } else if( fromWord.find(word[i]) == fromWord.end() || fromPattern.find(pattern[i]) == fromPattern.end() ) {
                    ok = false;
                } else if( fromWord[word[i]] != pattern[i] || fromPattern[pattern[i]] != word[i] ) { 
                    ok = false;
                }
            }
            if( ok ) { 
                res.push_back(word);
            }
        }
        
        return res;
    }
};

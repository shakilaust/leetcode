class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map < char, char > letters, reverseLetters;
        for( int i = 0 ; i < 26 ; i++ ) {
            letters[order[i]] = i + 'a';
            reverseLetters[ i + 'a'] = order[i];
        }
        vector < string > reverseWords;
        for( string word: words ) {
            string rv = "";
            for( char ch: word ) {
                rv += letters[ch];
            }
            reverseWords.push_back(rv);
            
        }
        sort( reverseWords.begin(), reverseWords.end() );
        for( int i = 0 ; i < reverseWords.size() ; i++ ) {
            string converted = "";
            for( char ch: reverseWords[i]) {
                converted += reverseLetters[ch];
            }
            if( converted != words[i] ) return false;
        }
        return true;
        
    }
};

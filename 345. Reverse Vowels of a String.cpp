class Solution {
public:
    
    bool isVowel( char ch) {
        if( ch == 'A' || ch == 'a' ) return true;
        if( ch == 'e' || ch == 'E' ) return true;
        if( ch == 'i' || ch == 'I' ) return true;
        if( ch == 'o' || ch == 'O' ) return true;
         if( ch == 'u' || ch == 'U' ) return true;
        return false;
    }
    string reverseVowels(string s) {
        stack < char > st;
        for( int i = 0 ; i < s.size() ; i++ ) {
            if( isVowel( s[i] ) ) {
                st.push(s[i]);
            }
        }
        for( int i = 0 ; i < s.size() ; i++ ) {
            if( isVowel( s[i] ) ) {
                s[i] = st.top();
                st.pop();
            }
        }
        
        return s;
    }
};

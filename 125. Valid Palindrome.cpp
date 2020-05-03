int charAscii(char ch) { 
    
    if( ch >= 'A' && ch <= 'Z' ) return ch - 'A';
    else if( ch >= 'a' && ch <= 'z' ) return ch - 'a';
    else return ch - '0' + 100;

}


class Solution {
public:
    bool isPalindrome(string s) {
        
        vector < int > asciiString;
        for( char ch: s ) { 
            if(isalnum(ch)) { 
                asciiString.push_back(charAscii(ch));
            }
        }
        
        for( int i = 0 , j = asciiString.size() - 1 ; i < j ; i++, j-- ) { 
            if( asciiString[i] != asciiString[j]) {
                return false;
            }
        }
        return true;
    }
};

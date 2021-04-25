
bool isVowel( char ch) {
    if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) {
        return true;
    }
    if( ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ) {
        return true;
    }
    return false;
}

class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S);
        string str;
        int idx = 1;
        bool space = false;
        string ans = "";
        while( ss >> str ) {
           // cout << " str " << str << endl;
            string add = "";
            if( isVowel( str[0] ) ) {
                add = str + "ma";
            } else {
                char ch = str[0];
                add = str.substr(1) + ch + "ma";
            }
            
            for( int i = 1 ; i <= idx ; i++ ) {
                add += "a";
            }
            idx++;
            
            if( space ) {
                ans += " ";
            }
          
           
            space = true;
            ans += add;
        }
        
        return ans;
    }
};

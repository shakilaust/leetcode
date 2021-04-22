class Solution {
public:
    bool isPalindrome( string &s, int l, int r, int rem ) {
        if( l >= r ) return true;
        if( s[l] != s[r]  ) {
            if( rem == 1 ) {
                return isPalindrome( s ,l + 1 , r,  0 ) || isPalindrome( s , l , r - 1 , 0 );
            }
            
            return false;
            
        } 
        return isPalindrome( s , l + 1, r - 1 , rem );
    }
    bool validPalindrome(string s) {
        return isPalindrome( s , 0 , s.size() - 1 , 1 );
    }
};

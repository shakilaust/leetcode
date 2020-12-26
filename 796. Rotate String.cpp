class Solution {
public:
    bool rotateString(string A, string B) {
        if( A == "" && B == "" ) return true;
        if( A.size() != B.size() ) {
            return false;
        }
        for( int i = 0 ; i < A.size() ; i++ ) {
            if( A.substr(i) + A.substr(0, i) == B ) return true;
        }
        return false;
    }
};

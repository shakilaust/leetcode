class Solution {
public:
    string generateAnswer( int &idxA, int &idxB, int carry, string &a, string &b) {
        if( idxA == a.size() && idxB == b.size() ) {
            if( carry ) return "1";
            else return "";
        }
        int now = carry;
        if( idxA < a.size() ) {
            now += ( a[idxA++] - '0' );
        }
        
        if( idxB < b.size() ) {
            now += ( b[idxB++] - '0');
        }
        carry = ( now / 2 );
        now = now % 2 ;
        if( now ) {
            return generateAnswer( idxA, idxB, carry, a, b ) + "1";
        } else {
            return generateAnswer( idxA, idxB, carry, a, b) + "0";
        }
    }
    string addBinary(string a, string b) {
        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        int idxA = 0;
        int idxB = 0;
        return generateAnswer( idxA, idxB, 0, a, b );
    }
};

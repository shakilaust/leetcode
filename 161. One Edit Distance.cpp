class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if( s == t ) return false;
        int ssz = s.size();
        int tsz = t.size();
        if( abs(ssz - tsz) > 1 ) return false;
        string small, big;
        if( s.size() == t.size() ) { 
                
            int notMatch = 0;
            for( int i = 0 ; i < s.size() ; i++ ) { 
                if( s[i] != t[i] ) notMatch++;
                if( notMatch > 1 ) return false;
            }
            return notMatch == 1 ? true : false;
        } else { 

            if( s.size() < t.size() ) { 
                small = s;
                big = t;
            } else {
                small = t;
                big = s;
            }

            int idx = 0;
            int sz = small.size();
            for( int i = 0 ; i < big.size() ; i++ ) { 
                if( big[i] == small[idx] ) idx++;
                if( idx == sz ) break;
            }
            
            return idx == sz ? true: false;
        }
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if( s == t ) return true;
        int sz = s.size();
        int tsz = t.size();
        bool found = false;
        for( int i = 0, sIdx = 0; i < tsz && !found ; i++ ) { 
            if( t[i] == s[sIdx] ) sIdx++;
            if( sIdx == sz ) found = true;
        }
        return found;
        
    }
};

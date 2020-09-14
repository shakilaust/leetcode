class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int sz = s.size();
        vector < int > prefixMatch( sz , 0 );
        
        int cur = 0;
        for( int i = 1 ; i < sz ; i++ ) { 

            while( cur > 0 && s[cur] != s[i] ) { 
                cur = prefixMatch[cur-1];
            }
            
            if( s[i] == s[cur] ) cur++;
            prefixMatch[i] = cur;
        }
        
        int mxPossibleLength = prefixMatch[sz-1];
        for( int len = 1 ;  len <= mxPossibleLength ; len++ ) { 
            
            if( sz % len > 0 ) continue;
            string subStr = s.substr(0, len);
            int total = sz / len; 
            string check = "";
            while(total--) check += subStr;
            if( s == check ) return true;
        }
        
        return false;
    }
};

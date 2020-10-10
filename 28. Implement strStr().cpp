class Solution {
public:
    int strStr(string haystack, string needle) {
        if( haystack == needle || needle == "" ) return 0;
        int nsz = needle.size();
        vector < int > prefix( nsz + 1 , 0 );
        int cur = 0;
        for( int i = 1 ; i <= nsz ; i++ ) { 
            while( cur > 0 && needle[cur] != needle[i] )  {
                cur = prefix[cur-1];
            }
            if( needle[cur] == needle[i] ) cur++;
            prefix[i] = cur;
        }
        
        cur = 0;
        for( int i = 0 ; i < haystack.size() ; i++ ) { 
            while( cur > 0 && haystack[i] != needle[cur] ) { 
                    cur = prefix[cur-1];
            }
            
            if( haystack[i] == needle[cur] ) cur++;
            if( cur == nsz ) {
                return i - nsz + 1;
            }
        }
        return -1;
    }
};

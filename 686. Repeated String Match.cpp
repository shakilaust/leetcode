class Solution {
public:
    int kmp( string searchString, string patternString ) {
        int psz = patternString.size();
        vector < int > prefix( psz + 1 , -1 );
        prefix[0] = 0;
        int x = 0;
        for( int y = 1 ; y < psz ; y++ ) {
            
            while( x > 0 && patternString[x] != patternString[y] ) {
                x = prefix[x - 1];
             
            }
            
            if(patternString[x] == patternString[y] ) x++;
            prefix[y] = x;
          
        }
      
        int match = 0;
        for( int i = 0 ; i < searchString.size() ; i++ ) {
            while( match > 0 && searchString[i] != patternString[match]) {
                match = prefix[match - 1];
            }
            if( patternString[match] == searchString[i] ) match++;
            if( match == psz ) {
                return i - match + 1;
            }
        }
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
        string searchString = "";
        int done = 0;
        while( searchString.size() < b.size() ) {
            searchString += a;
            done++;
        }
        if( kmp( searchString, b ) > -1 ) {
            return done;
        }
        searchString += a;
        if( kmp(searchString, b ) > -1 ) {
            return done + 1;
        }
        return -1;
        
    }
};

class Solution {
public:
    bool canConstruct(string A, string B) {
        vector< int > freqA( 26, 0 );
        vector < int > freqB( 26, 0 );
        for( char ch: A ) { 
            freqA[ch-'a']++;
        }
        
        for( char ch: B) { 
            freqB[ch-'a']++;
        }
        
        for( int i = 0 ; i < 26 ; i++ ) { 
            if( freqA[i] > freqB[i] ) { 
                return false;
            }
        }
        return true;
    }
};

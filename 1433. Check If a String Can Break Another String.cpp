

bool isPossible( vector< int > freqA, vector < int > freqB ) { 
    
    int a = 0, b = 0;
    for( int i = 25 ; i >= 0 ; i-- ) { 
        a += freqA[i];
        b += freqB[i];
        if( a > b ) return false;
    }
    return true;

}


class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector < int > freqA( 26, 0 );
        vector < int > freqB( 26, 0 );
        for( int i = 0 ; i < s1.size() ; i++ ){ 
            freqA[s1[i]-'a']++;
            freqB[s2[i]-'a']++;
        }
        
        if( isPossible(freqA, freqB) || isPossible(freqB, freqA ) ) return true;
        return false;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector < int > fromS ( 512, -1 );
        vector < int > fromT (512, -1 );
        
        int ssz = s.size();
        int tsz = t.size();
        if( ssz != tsz ) return false;
        for( int i = 0 ; i < ssz ; i++ ) { 
            int sChar = s[i] ;
            int tChar = t[i] ;
            
            if( fromS[sChar] != -1 || fromT[tChar] != -1 ) { 
                if( fromS[sChar] != tChar || fromT[tChar] != sChar ) { 
                    return false;
                }   
            } else { 
                fromS[sChar] = tChar;
                fromT[tChar] = sChar;
            }
        }
        
        return true;
    }
};

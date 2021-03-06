const int mod = 1e9 + 7;
const int NX = 55;
int totalLength, evilLength;
int evilT[ NX ];
int dp[ 502 ][ 2 ][ 2 ][ 52 ];
string small, big, bad;

int DP( int pos, int isSmall, int isBigger, int matchSoFarEvil) { 
    if( evilLength == matchSoFarEvil ) { 
        return 0;
    }
    if( totalLength == pos ) { 
        return 1;
    }    
    
    int &ret = dp[ pos ][ isSmall ][ isBigger ][ matchSoFarEvil ];
    if( ret != -1 ) return ret;
    ret = 0;
    int start = isBigger == 0 ? small[pos] - 'a' : 0;
    int end = isSmall == 0 ? big[pos] - 'a' : 25;
    
    for( int i = start ; i <= end ; i++ ) { 
         int nxtMatchSoFarEvil = matchSoFarEvil;
        int nowEvail = bad[matchSoFarEvil] - 'a' ;
        while( nxtMatchSoFarEvil > 0 && (bad[nxtMatchSoFarEvil] - 'a') != i ) { 
            nxtMatchSoFarEvil = evilT[nxtMatchSoFarEvil];
        }
        if( i == bad[nxtMatchSoFarEvil] - 'a' ) nxtMatchSoFarEvil++;
       
        int nxtIsSmall = isSmall || (big[pos] - 'a' > i );
        int nxtIsBigger = isBigger || (small[pos] - 'a' < i );
        ret += DP( pos + 1 , nxtIsSmall,  nxtIsBigger, nxtMatchSoFarEvil) % mod;
        ret %= mod;
       
    }
    return ret;

}

class Solution {
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        totalLength = n;
        small = s1;
        big = s2;
        bad = evil;
        evilLength = evil.size();
        evilT[0] = 0;
        evilT[1] = 0;
        int k = 0;
        for( int i = 0 ; i <= totalLength ; i++ ) { 
            for( int j = 0 ; j < 2 ; j++ ) { 
                for( int k = 0 ; k < 2 ; k++ ) { 
                    for( int l = 0 ; l <= evilLength ; l++ ) {
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }
        for( int idx = 2; idx <= evil.size() ; idx++ ) { 
            while( k > 0 && evil[k] != evil[idx-1] ) k = evilT[k];
            if(evil[k] == evil[idx-1]) k++;
            evilT[idx] = k;
        }
        return DP( 0 , 0 , 0 , 0 );
    }
};

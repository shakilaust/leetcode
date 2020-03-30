int par[26];
int findParent( int x) { 
    if( x == par[x] ) return x;
    return par[x] = findParent(par[x]);

}

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
       
        for( int i = 0 ; i < 26 ; i++ ) { 
            par[i] = i;
        }
        for( int i = 0 ; i < A.size() ; i++ ) { 
            int x = A[i] - 'a';
            int y = B[i] - 'a';
            x = findParent(par[x]);
            y = findParent(par[y]);
            if( x < y ) par[y] = x;
            else par[x] = y;
        }

        for( int i = 0 ; i < S.size() ; i++ ) { 
            int now = S[i] - 'a';
            S[i] = findParent(now) + 'a';
        }
        return S;
    }
};

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int sz = S.size();
        int nxtLetter[ sz + 1 ][ 26 ];
        for( int i = 0 ; i < 26 ; i++ ) nxtLetter[sz][i] = -1; // -1 means not available
        for( int i = sz - 1 ; i >= 0 ; i-- ) { 
            int cur = S[i] - 'a';
            nxtLetter[i][cur] = i + 1;
            for( int j = 0 ; j < 26 ; j++ ) { 
                if( cur == j ) continue;
                nxtLetter[i][j] = nxtLetter[i+1][j];
            }
        }
        
        int ans = 0;
        int wsz = words.size();
        for( int i = 0 ; i < wsz ; i++ ) { 
            int idx = 0;
            sz = words[i].size();
            int nxt = 0;
            
            while( idx < sz ) { 
                int cur = words[i][idx] - 'a';
                if( nxtLetter[nxt][cur] == -1 ) break;
                nxt = nxtLetter[nxt][cur];
                idx++;
                
            }
            if( idx == sz ) ans++;
        }
        return ans;
    }
};

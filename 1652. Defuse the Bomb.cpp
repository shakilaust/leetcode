class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        bool isReverse = k < 0 ? true : false;
        if( k < 0 ) k *= -1;
        int sz = code.size();
        vector < int > ans( sz , 0 );
        if( k == 0 ) return ans;
        for( int i = 0 ; i < sz ; i++ ) { 
            
            int add = isReverse ? -1 : 1;
            int idx = k;
            int cur = i;
            int total = 0;
            while( idx > 0 ) {
                int nxt = ( cur + add + sz ) % sz;
                total += code[nxt];
                cur = cur + add;
                idx--;
                
            }
            
            ans[i] = total;
        
        }
        return ans;
    }
};

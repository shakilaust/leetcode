class Solution {
    
bool ok( vector< int > &a, vector< int > &b) {

    for( int i = 0 ; i < 26 ; i++ ) {
        if( a[i] != b[i] ) return false;
    }
    return true;
}
public:
    bool checkInclusion(string s1, string s2) {
        vector < int > freq1( 26, 0 );
        vector < int > freq2( 26, 0 );
        
        for( char ch: s1 ) {
            freq1[ch-'a']++;
        }
        
        int low = 0;
        int sz = s1.size();
        bool ans = false;
        for( int i = 0 ; i < s2.size() && !ans ; i++ ) {
            
            freq2[s2[i] - 'a']++;
            if( i - low + 1 == sz ) {
                ans = ok(freq1, freq2);
              
            }
            
            if( i - low + 1 == sz ) {
                freq2[s2[low++] - 'a']--;
            }

        }
        
       
        return ans;
    }
};

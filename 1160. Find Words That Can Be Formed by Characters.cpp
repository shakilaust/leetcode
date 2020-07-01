class Solution {
public:
    
    bool ok( vector< int > &a, vector< int > &b) { 
            
        for( int i = 0 ; i < 26 ; i++ ) { 
            if( b[i] > a[i] ) { 
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector < int > freq( 26, 0 );
        
        int sz = chars.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            freq[chars[i] - 'a']++;
        }
        
        int ans = 0;
        int totalSz = words.size();
        for( int i = 0 ; i  < totalSz ; i++ ) { 
            sz = words[i].size();
            vector < int > wordFreq( 26, 0 );
            for( int j = 0 ; j < sz ; j++ ) { 
                wordFreq[words[i][j] - 'a']++;
            }
            if( ok( freq, wordFreq) ) { 
                ans += sz;
            }
        }
        return ans;
        
    }
};

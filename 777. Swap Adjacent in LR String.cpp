class Solution {
public:
    bool canTransform(string start, string end) {
        
        int cnt = 0;
        int sz = start.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            if( start[i] == 'X' ) cnt++;
            if( end[i] == 'X' ) cnt--;
        }
        
        if( cnt != 0 ) return false;
        int i = 0, j = 0;
        
        while( i < sz && j < sz ) { 

            while( i < sz && start[i] == 'X' ) i++;
            while( j < sz && end[j] == 'X' ) j++;
            
            if( i == sz || j == sz ) return  i == sz && j == sz;
            
            if( start[i] != end[j] ) return false;
            if( start[i] == 'L' && i < j ) return false; // L always comes left;
            if( start[i] == 'R' && i > j ) return false; // R always comes right;
            i++;
            j++;
        }
        
        return true;
    }
};

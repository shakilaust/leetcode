/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    
    bool celebrity( int x, int n ) { 
        for( int i = 0 ; i < n ; i++ ) { 
            if( i == x ) continue;
            if( knows(x , i ) || !knows(i, x ) ) return false;
        }
        
        return true;

    }
    int findCelebrity(int n) {
        int ans = -1;
     
        for( int i = 0 ; i < n ; i++ ) { 

            if(celebrity(i, n)) return i;
        }
        
        return -1;
    }
};

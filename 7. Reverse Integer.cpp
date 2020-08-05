class Solution {
public:
    int reverse(int x) {
        long newOne = 0;
        bool neg = false;
        if( x == INT_MIN ) return 0;
        if( x < 0 ) { 
            x *= -1;
            neg = true;
        }
        while( x > 0 ) { 

            int md = x % 10;
            newOne = ( newOne * 10 ) + md;
            x /= 10;
        }
        
        if( neg ) { 
            newOne *= -1;
        }
        
        if( newOne > INT_MAX || newOne < INT_MIN ) return 0;
        
        return newOne;
    }
};

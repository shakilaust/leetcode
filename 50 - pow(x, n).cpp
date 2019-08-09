class Solution {
public:
    double myPow(double x, int n) {
        bool divide = n < 0 ? true : false;
        if( n == 0 ) return 1.00;
        if( n < 0 ) n *= -1;
        
        for( int i = 2 ; i <= n / i ; i++ ) { 
            
            while( n % i == 0 ) { 
                 
                 x = pow(x , i);
                 n /= i;
                
            }
        }
        
        if( n > 1 ) x = pow( x , n );
        if( divide ) return 1.00 / x ;
        return x;
    }
};

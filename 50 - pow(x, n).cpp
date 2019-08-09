class Solution {
public:
    double myPow(double x, int n) {
        bool divide = n < 0 ? true : false;
        if( n == 0 ) return 1.00;
        long long int pw = n; // comparison not working
        if( pw < 0 ) pw = pw * -1;;
        
        for( int i = 2 ; i <= pw / i ; i++ ) { 
            
            while( pw % i == 0 ) { 
                 
                 x = pow(x , i);
                 pw /= i;
                
            }
        }
        
        if( pw > 1 ) x = pow( x , pw );
        if( divide ) return 1.00 / x ;
        return x;
    }
};

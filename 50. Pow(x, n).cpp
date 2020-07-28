class Solution {
public:
    
    double fastPower( double x,  long long N) { 
        if( N == 0 ) { 
            return 1.0;
        }
        
        double ans = fastPower( x , N / 2 );
        if( N % 2 == 0 ) { 
            return ans * ans;
        } else return ans * ans * x;

    }
    double myPow(double x, int n) {
        long long int N = n;
        if( N < 0 ) { 
            x = 1/x;
            N = -N;
        }
        
        return fastPower( x , N );
    }
};

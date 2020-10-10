class Solution {
public:
    int countPrimes(int n) {
        vector < int > primes;
        if( n <= 2 ) return 0;
       
        primes.push_back(2);
        vector < bool > isPrime( n , true );
        
        for( long long int i = 3 ; i < n ; i += 2 ) {
            if( isPrime[i] == true ) {
                primes.push_back(i);
                for( auto j = i * i ; j < n ; j += ( 2 * i ) ) { 
                    isPrime[j] = false;
                }
            }
        }
        
        return primes.size();
    }
};

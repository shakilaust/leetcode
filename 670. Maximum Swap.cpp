class Solution {
public:
    int maximumSwap(int num) {
        if( num == 0 ) return num;
        vector < int > digits;
        while( num > 0 ) { 
            digits.push_back( num % 10 );
            num /= 10;
        }
        int sz = digits.size();
        bool alreadyFound = false;
        for( int i = sz - 1 ; i >= 0 && !alreadyFound ; i-- ) { 

               int mx = -1, pos;
               for( int j = 0 ; j < i ; j++ ) { 
                    if(digits[j] > digits[i] && mx < digits[j]) {
                        mx = digits[j];
                        pos = j;
                    }
              }
              if( mx > -1 ) {
                    swap( digits[i], digits[pos] );
                    alreadyFound = true;
              }
        }

        int res = 0;
        int multiple = 1;
        for( int i = 0 ; i < sz ; i++, multiple *= 10 ) { 
            res += ( multiple * digits[i] );
        }
        return res;
    }
};

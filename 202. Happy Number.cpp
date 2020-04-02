class Solution {
public:
    bool isHappy(int n) {
      
        unordered_map < long, bool > present;
        long cur = n;
        while(present[cur] == false ) {

            present[cur] = true;
            long newNumber = 0;
            while( cur > 0 ) { 

                int digit = ( cur % 10 );
                cur /= 10;
                newNumber += ( digit * digit );
            }
            
            if( newNumber == 1 ) return true;
            cur = newNumber;

        }
        
        
        return false;
    }
};

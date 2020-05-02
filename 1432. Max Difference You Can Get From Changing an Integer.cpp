void change(vector< int > &nums, int check, int repValue) { 
     
    for( int i = 0 ; i < nums.size() ; i++ ) { 
            if( nums[i] == check ) { 
                nums[i] = repValue;
             }
        }
 

}

class Solution {
public:
    int maxDiff(int num) {
        vector < int > a, b;
        int sv = num, lastDigit = -1;
        while( num > 0 )  { 
            int d = num % 10;
            a.push_back( d );
            b.push_back( d );
            num /= 10;
            lastDigit = d;
        }
        
        int replaceA = 9, replaceB = 1;
        
        for( int i = a.size() - 1 ; i >= 0 ; i-- ) { 
            if( a[i] != 9 ) { 
                replaceA = a[i];
                break;
           }
        }
        
        bool secondIdx = false;
        
         for( int i = b.size() - 1 ; i >= 0 ; i-- ) { 
            if( b[i] > 1 ) { 
                replaceB = b[i];
                if( i != b.size() - 1 ) { 
                    secondIdx = true;
                }
                break;
           }
      
        }
        
        change( a, replaceA, 9 );
        change( b, replaceB, secondIdx ? 0 : 1 );
        
        
        
        
      
        int ans = 0, mul = 1;
        for( int i = 0 ; i < a.size() ; i++ ) { 
            int d = ( a[i] - b[i] );
            ans = ans + ( d * mul );
            mul = mul * 10;
        }
        
        return ans;

        
    }
};

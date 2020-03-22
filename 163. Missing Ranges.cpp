string reverseString(string currentString) { 

        int sz = currentString.size();
        for( int x = 0, y = sz - 1 ; x < y ; x++, y-- ) swap(currentString[x], currentString[y]);
        return currentString;
}



long long int diff( long long int a, long long int b ) { 
    return a - b;

}
string intToString(long long int number) { 
        
        string res = number == 0 ? "0" : "";
        bool isNegative = number < 0 ? true : false;
        if( number < 0 ) number *= -1;
        while( number > 0 ) { 
    
            res += (( number % 10 ) + '0');
            number /= 10;
        }
        if(isNegative) {
            return "-" + reverseString(res);
        }
    
        return reverseString(res);
        

    }


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector < string > ans;
          string add;
        int sz = nums.size();
        if( sz == 0 ) { 
            if(lower == upper ) { 
                 add = (intToString(lower) );
            } else { 
                 add = intToString( lower ) + "->" + (intToString( upper ) );
            }
            ans.push_back(add);
            return ans;
        }
      
        int idx = 0;
        if(diff(nums[0], lower)>= 1 ) { 
            if(diff(nums[0], lower) == 1 ) { 
                 add = (intToString(lower ) );
            } else {
                add = intToString( lower ) + "->" + (intToString(nums[0] - 1 ) );
             }
            ans.push_back(add);
        }
        for( int i = 1 ; i < sz ;i++ ) { 
            if(diff(nums[i], nums[i-1]) > 1 ) { 
                if( diff(nums[i], nums[i-1]) == 2 ) {
                    add = (intToString(nums[i] - 1 ) );
                } else { 
                    add = (intToString(nums[i - 1] + 1 ) ) + "->" + (intToString(nums[i] - 1 ) );
                 }
                ans.push_back(add);
            }
        }

         if(diff(upper, nums[sz-1]) >= 1 ) { 
            if( diff(upper, nums[sz-1])== 1 ) { 
                 add = (intToString(upper ) );
            } else  {
                add = intToString( nums[sz-1] + 1 )  + "->" + (intToString(upper) );
            }
             ans.push_back(add);
         }
        
        
        return ans;
        
    }
};

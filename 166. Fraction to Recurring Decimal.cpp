class Solution {
public:
    string fractionToDecimal(int num, int den) {
        
        if( num == 0 ) return "0";
        if( den == 1 ) return to_string(num);
        if(num==INT_MAX&&den==-1)return to_string(INT_MIN) ;
        if(num==INT_MIN&&den==-1)return "2147483648" ;
        string sign = "";
        if( ( num < 0 && den > 0 ) || ( num > 0 && den < 0 ) ) sign = "-";
        num = abs( num );
        den = abs( den );
        string ans = sign + to_string(num/den);
       
      
        unordered_map < long long int, int > check;
        int idx = 0;
        long long int rem = num % den;
        if( !rem ) return ans;
        ans += ".";
        string afterFloat = "";
        while( rem > 0 ) {
            check[rem] = idx++;
            afterFloat += to_string(rem * 10 / den );
            rem = ( rem * 10 ) % den;
            if( check.find( rem ) != check.end() ) {
                afterFloat.insert(check[rem], "(");
                ans += afterFloat;
                ans += ")";
                return ans;
            }
        }
        
        return ans + afterFloat;
    }
};

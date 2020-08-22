class Solution {
public:
    string addStrings(string num1, string num2) {
        int sz1 = num1.size() - 1;
        int sz2 = num2.size() - 1;
        string  ans = "";
        int carry = 0;
        while( sz1 >= 0 || sz2 >= 0 || carry > 0 ) { 
            int value = carry;
            if( sz1 >= 0 ) { 
                value += (num1[sz1--] - '0');
            }
            
              if( sz2 >= 0 ) { 
                value += (num2[sz2--] - '0');
            }
            
            carry = value / 10;
            value = value % 10;
            ans = to_string(value) + ans;
            //cout << " value " << value << " carry " << carry << endl;
        }
        
        return ans;
    }
};

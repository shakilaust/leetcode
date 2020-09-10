class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        int sz1 = num1.size();
        int sz2 = num2.size();
        int total = sz1 + sz2 ;
        vector < vector < int > > multiplications( total , vector < int > (0) );
        
        int startIdx = 0;
        while( sz2-- ) { 
            
            int b = num2[sz2] - '0' ;
            
            int carry = 0, i, j;
            for( i = sz1 - 1, j = startIdx ; i >= 0 ; i-- , j++ ) { 
                
                int a = num1[i] - '0';
                int value = ( a * b ) + carry;
              //   cout << " i " << i << " j " << j << " value " << value << endl;
                multiplications[j].push_back(value % 10 );
                carry = value / 10;

            }
            
            if( carry > 0 ) multiplications[j].push_back(carry);
            
            
            
            startIdx++;
            
        }
        
        
        int carry = 0;
        
        for( int i = 0 ; i < total  ; i++ ) { 
            
            
          //  cout << " multiplications[i].size() " << multiplications[i].size() << endl;
            if( multiplications[i].size() == 0 ) continue;
            int value = 0;
            for( int j = 0 ; j < multiplications[i].size(); j++ ) { 
                value += multiplications[i][j];
            }
            
            value += carry;
            
          //  cout << " final " << value << endl;
            ans += to_string(value % 10);
            carry = value /= 10;
        }
        
        if( carry > 0 ) ans += to_string( carry );
        
        for( int i = ans.size() - 1 ; i >= 0 ; i-- ) { 
            if( ans[i] != '0' ) break;
            ans.pop_back();
        }
        
        reverse( ans.begin(), ans.end() );
        
        return ans.size() == 0 ? "0" : ans;
        
    }
};

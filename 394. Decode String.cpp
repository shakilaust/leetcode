class Solution {
    
    
    string getAns( string inp, int &pos) { 
        
        string ans = "";
        int num = 0;
        
        for( ; pos < inp.size() ; pos++ ) { 

            if( inp[pos] >= '0' && inp[pos] <= '9') { 
                num = num * 10 + (inp[pos] - '0');
            } 
            else if( inp[pos] == '[') { 
                string tmp = getAns( inp, ++pos );
              //  cout << " tmp " << tmp << " num " << num << endl;
                while( num-- > 0 ) ans += tmp;
                num = 0;
             //   cout << " here " << ans << endl;
            } else if( inp[pos] == ']') {
                    return ans;
            } else { 
                ans += inp[pos];
            }
            
          //  cout << " pos " << pos << " ans " << ans << endl;
        } 
        
        return ans;
    
    
    }
public:
    string decodeString(string s) {
        int pos = 0;
        return getAns(s, pos );
    }
};

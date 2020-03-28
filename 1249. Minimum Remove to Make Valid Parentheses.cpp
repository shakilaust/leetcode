class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        int values = 0;
        for( int i = 0 ; i < s.size() ; i++ ) { 
            
            if(s[i] == ')') {
                if( values > 0 ) { 
                    ans += s[i];
                    values--;
                }
              
            } else ans += s[i];
            
            if( s[i] == '(') values++;

        }
        
        values = 0;
        for( int i = ans.size() - 1 ; i >= 0 ; i-- ) { 

            if(ans[i] == '(') {
                if( values == 0 ) {
                    ans = ans.substr(0, i) + ans.substr(i+1);
                } else values--;
            } else if( ans[i] == ')') values++;
        }
        
        return ans;
    }
};

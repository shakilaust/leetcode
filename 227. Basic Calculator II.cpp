class Solution {

bool performOperation( char now ) { 
    
    if( !isdigit(now) && !isspace(now) ) { 
        return true;
    }
    
    return false;

}
public:
    int calculate(string s) {
        stack < int > myStack;
        int res = 0, tmp = 0;
        char sign = '+';
        for( int i = 0; i < s.size() ; i++ ) { 
            if( isdigit(s[i])) {
                tmp = ( tmp * 10 ) + ( s[i] - '0');
            }
            
            if( performOperation( s[i] ) || i == s.size() - 1 ) { 

                if( sign == '+' ) { 
                    myStack.push(tmp);
                } else if( sign == '-' ) { 
                    myStack.push(-tmp);
                } else { 
                    int val;
                    if( sign == '*' ) {
                        val = myStack.top() * tmp;
                    } else {
                        val = myStack.top() / tmp;
                    }
                    
                    myStack.pop();
                    myStack.push(val);

                }
                sign = s[i];
                tmp = 0;
            }


        }
        
        while( !myStack.empty()) { 
            res += myStack.top();
            myStack.pop();
        }
        
        return res;
    }
};

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        set < string > visited;
        queue < string > q;
        queue < int > cost;
        for( string str: deadends ) {
           visited.insert(str);
        }
        
        if( visited.find("0000") != visited.end()) {
            return -1;
        }
        
        q.push("0000");
        cost.push(0);
        visited.insert("0000");
        if( q.front() == target ) return 0;
        while( !q.empty()) {
            string now = q.front();
            int c = cost.front();
            cost.pop();
            q.pop();
            string newString = now;
            for( int i = 0 ; i < 4 ; i++ ) {
                for( int j = -1 ; j <= 1 ; j+=2) {
                    int newDigit = ((now[i] - '0') + j + 10 ) % 10;
                    newString[i] = newDigit + '0';
                    cout << " move " << newString << endl;
                    if( visited.find(newString) == visited.end() ) {
                        if( newString == target ) {
                            return c + 1;
                        }
                        visited.insert(newString);
                        q.push( newString );
                        cost.push( c + 1 );
                    }
                   
                    
                }
                 newString[i] = now[i];
                    
            }
            
            
        }
        
        
        
        return -1;
        
    }
};

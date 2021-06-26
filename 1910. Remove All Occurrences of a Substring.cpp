class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack < string > st;
        st.push("");
        int pLen = part.size();
        for( int i = 0 ; i < s.size() ;  i++ ) {
            string fromSt = st.top();
            st.pop();
            fromSt += s[i];
            if( fromSt.size() >= pLen ) {
                
                if( fromSt.substr( fromSt.size() - pLen) == part ) {
                    fromSt = fromSt.substr(0, fromSt.size() - pLen );
                }
            } 
            st.push(fromSt);
        }
        
        
        return st.top();
    }
};

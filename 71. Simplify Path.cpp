class Solution {
public:
    string simplifyPath(string path) {
        stack < string > st;
        int len = path.size();
        if( path[len - 1] != '/' ) {
            path += "/";
            len++;
        }
        
        string prv = "";
        for( int i = 0 ; i < len ; i++ ) {
            if( path[i] == '/' ) {
                if( prv == ".." ) {
                    if( !st.empty() ) {
                        st.pop();
                    }
                } else if( !( prv == "" || prv == "." ) ) {
                    st.push( prv );
                }
                prv = "";
            } else {
                prv += path[i];
            }
        }
        
        string ans = "";
        while( !st.empty() ) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        
        if( ans.size() == 0 ) {
            ans += "/";
        }
        
        return ans;
    }
};

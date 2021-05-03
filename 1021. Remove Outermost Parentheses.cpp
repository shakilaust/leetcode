class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans = "";
        int sz = S.size();
        vector < bool > canTake( sz , true );
        stack < int > st;
        int cnt = 0;
        for( int i = 0 ; i < S.size() ; i++ ) {
            if( S[i] == '(') {
                st.push(i);
                cnt++;
            } else {
                int t = st.top();
                cnt--;
                if( cnt == 0 ) {
                    canTake[i] = false;
                    canTake[t] = false;
                } 
                st.pop();
            }
        }
        
        for( int i = 0 ; i < sz ; i++ ) {
            if( canTake[i] ) {
                ans += S[i];
            }
        }
        return ans;
    }
};

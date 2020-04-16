class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack < pair< char, int > > st;
        for( int i = 0 ; i < s.size() ; i++ ) { 
            int cnt = 1;
            if( !st.empty() && st.top().first ==  s[i] ) { 
                cnt += st.top().second;
                st.pop();
            }
            
            if( cnt < k ) st.push({s[i], cnt } );
        }
        string ans = "";
        while(!st.empty()) { 
            for( int i = 0 ; i < st.top().second ; i++ ) { 
                ans += st.top().first;
            }
            st.pop();
        }

        if( ans.size() > 0 ) reverse( ans.begin(), ans.end());
        return ans;
    }
};

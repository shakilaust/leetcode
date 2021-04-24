class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector < int > ans( n, 0 );
        stack < int > st;
        int lst = 0;
        for( string str: logs) {
            stringstream ss( str );
            string s_idx, s_status, s_end;
            getline( ss, s_idx, ':');
            getline( ss, s_status, ':');
            getline( ss, s_end, ':' );
            int idx = stoi(s_idx);
            int endTime = stoi(s_end);
            if( s_status == "start" ) {
                if( !st.empty() ) {
                    ans[st.top()] += ( endTime - lst );
                }
                lst = endTime;
                st.push(idx);
            } else {
                ans[st.top()] += ( endTime - lst + 1 );
                lst = endTime + 1;
                st.pop();
            }
            
        }
        return ans;
    }
};

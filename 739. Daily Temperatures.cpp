class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int sz = T.size();
        vector < int > ans( sz , 0);
        stack < int > st;
        for( int i = sz - 1 ; i >= 0 ; i-- ) {
            
            while(!st.empty() && T[i] >= T[st.top()] ) st.pop();
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
        
    }
};

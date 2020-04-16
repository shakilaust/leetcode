class Solution {
public:
    string removeDuplicates(string S) {
        stack < char > st;
        for(char ch: S) { 
            if(!st.empty() && st.top() == ch ) {
                st.pop();
                
            } else st.push(ch);
        }   
        
        string ans = "";
        while(!st.empty()) { 
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

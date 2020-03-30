class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        stack < int > st;
        for(int num : nums ) { 

            while(!st.empty() && num < st.top() ) st.pop();
            st.push(num);
            ans += st.size();
        }
        
        
        return ans;
    }
};

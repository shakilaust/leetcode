class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
          int sz = nums.size();
          stack < int > st;
          vector < int > ans(sz, -1 );
          for( int i = sz + sz - 1 ; i >= 0 ; i-- ) { 
            while( !st.empty() && nums[st.top()] <= nums[i % sz ] ) st.pop();
            ans[i % sz ] = st.empty() ? -1 : nums[st.top()];
             st.push(i%sz);
         }
        
        return ans;
    
    }
};

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        stack < int > st;
        for( int i = 0 ; i < nums.size() ; i++ ) { 
            if( !st.empty() ) { 
                if( st.top() != nums[i] ) break;
                else st.pop();
            } else st.push(nums[i]);
        }
        
        return st.top();
    }
};

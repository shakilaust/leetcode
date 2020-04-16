class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& inp, vector<int>& nums) {
        vector < int > ans;
        stack < int > st;
        unordered_map < int, int > mp;
        for( int n: nums) { 
            while( !st.empty() && st.top() < n ) { 
                mp[st.top()] = n;
                st.pop();
            }
            st.push(n);
        }
        for( int num: inp ) { 
            ans.push_back( mp.count(num) ? mp[num] : -1 );
        }
        return ans;
    }
};

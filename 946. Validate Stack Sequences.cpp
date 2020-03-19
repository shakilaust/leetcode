class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack < int > st;
        int push = 0;
        int pop = 0;
        while( push < pushed.size() ) { 
            
            if( pop < popped.size() && !st.empty() && st.top() == popped[pop] ) { 
                pop++;
                st.pop();
            } else {
                st.push(pushed[push++]);
            }

        }
        
        while( pop < popped.size() ) { 

            if( push == pushed.size()) { 
                if( !st.empty() && popped[pop] == st.top()) { 
                    pop++;
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        return true;
    }
};

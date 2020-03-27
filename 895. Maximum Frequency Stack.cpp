class FreqStack {

unordered_map < int, int> freq;
unordered_map < int, stack<int> > st;
int mxFreq;
public:
    FreqStack() {
        mxFreq = 0;
        freq.clear();
        st.clear();
    }
    
    void push(int x) {
        mxFreq = max(mxFreq , ++freq[x]);
        st[freq[x]].push(x);
    }
    
    int pop() {
       int res = st[mxFreq].top();
       st[mxFreq].pop();
       if(!st[freq[res]--].size()) mxFreq--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */

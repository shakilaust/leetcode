class CustomStack {
private:
    vector < int > myStack;
    int mxIdx = 0;
public:
    CustomStack(int maxSize) {
        mxIdx = maxSize;
        myStack.clear();
    }
    
    void push(int x) {
        if(myStack.size() < mxIdx ) {
            myStack.push_back(x);
        }
        
    }
    
    int pop() {
        int ans = -1;
        if(myStack.size() > 0 ) {
            
            ans = myStack[myStack.size() - 1 ];
            myStack.pop_back();
        }
        
        return ans;
        
    }
    
    void increment(int k, int val) {
        int sz = myStack.size();
        sz = min( k , sz );
        for( int i = 0 ; i < sz ; i++ ) { 
            myStack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

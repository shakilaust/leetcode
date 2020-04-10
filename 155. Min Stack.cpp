class MinStack {

  deque < int > dq;
  int element = 0;
public:
    /** initialize your data structure here. */
    MinStack() {
        while(!dq.empty()) dq.pop_back();
        element = 0;
    }
    
    void push(int x) {
     
       dq.push_back(x);
        element++;
   
        if(dq.front() >= x ) dq.push_front(x);
    }
    
    void pop() {
        if( element == 0 ) { 
            while(!dq.empty()) dq.pop_back();
        } else { 
            
            if( dq.back() == dq.front() ) { 
                dq.pop_back();
                if(!dq.empty()) dq.pop_front();
            } else dq.pop_back();
            element--;
        }
    }
    
    int top() {
       return dq.back();
       
    }
    
    int getMin() {
      return dq.front();
       
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

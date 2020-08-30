class DinnerPlates {
    unordered_map < int , list < int > > stk;
    int cap, lft = 0, rgt = 0;
public:
    DinnerPlates(int capacity) {
        stk.clear();
        cap = capacity;
        lft = 0;
        rgt = 0;
    }
    
    void push(int val) {
        
        while( stk[lft].size() == cap ) lft++;
        stk[lft].push_back(val);
        rgt = max( rgt, lft );
    }
    
    int pop() {
        

        while( rgt >= 0 && stk[rgt].size() == 0 ) rgt--;
        
        if( rgt < 0 ) return -1;
        int val = stk[rgt].back();
        stk[rgt].pop_back();
        lft = min( lft, rgt );
        return val;
    }
    
    int popAtStack(int index) {
        if(  stk[index].size() > 0 ) { 
            int val = stk[index].back();
            stk[index].pop_back();
            lft = min(lft, index );
            return val;
        }
        
        return -1;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

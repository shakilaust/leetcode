class StockSpanner {
stack < pair< int, int> > st;
int idx = 0;
public:
    StockSpanner() {
        while(!st.empty()) st.pop();
        idx = 0;
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price ) st.pop();
        int ans = 1;
        if( st.empty() ) {
            st.push({price, idx++});
            ans = idx;
        } else {
            ans = idx - st.top().second;
            st.push({price, idx++});
        }
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

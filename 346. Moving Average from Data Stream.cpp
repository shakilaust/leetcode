class MovingAverage {
    queue < int > q;
    double total = 0;
    int mxsz = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        total = 0;
        while(!q.empty()) q.pop();
        mxsz = size;
    }
    
    double next(int val) {
        if( q.size() == mxsz) { 
            total -= q.front();
            q.pop();
        }
        total += val;
        q.push(val);
        return total / (double) q.size();
    }
};

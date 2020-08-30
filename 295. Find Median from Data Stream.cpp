class MedianFinder {
    priority_queue<int> low;            // max Heap               
    priority_queue<int, vector<int>, greater<int>> high;  // min heap
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        low.push( num );
        high.push( low.top());
        low.pop();
        if( low.size() < high.size() ) { 
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
       return low.size() > high.size() ? low.top() : ((double) low.top() + high.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

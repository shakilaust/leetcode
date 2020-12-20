class BrowserHistory {
public:
    unordered_map < int, string > visits;
    int curIdx, endIdx;
    BrowserHistory(string homepage) {
      endIdx = 0;
      curIdx = 0;
      visits[curIdx] = homepage;
    }
    
    void visit(string url) {
      visits[++curIdx] = url;
      endIdx = curIdx;
       
    }
    
    string back(int steps) {
       if( curIdx < steps ) {
           curIdx = 0;
       } else curIdx -= steps;
        return visits[curIdx];
    }
    
    string forward(int steps) {
        curIdx += steps;
        if( curIdx > endIdx ) {
            curIdx = endIdx;
        }
        return visits[curIdx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

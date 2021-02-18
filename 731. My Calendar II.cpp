class MyCalendarTwo {
    map < int, int > treeMap;
public:
    MyCalendarTwo() {
        treeMap.clear();
    }
    
    bool book(int start, int end) {
        if( treeMap.find(start) == treeMap.end() ) {
            treeMap[start] = 0;
        } 
        if( treeMap.find(end) == treeMap.end() ) {
            treeMap[end] = 0;
        }
        treeMap[start] += 1;
        treeMap[end] -= 1;
        int cnt = 0;
        for( pair < int, int > item: treeMap ) {
            cnt += item.second;
            
            if( cnt >= 3 ) {
                treeMap[start] -= 1;
                treeMap[end] += 1;
                if( treeMap[start] == 0 ) {
                    treeMap.erase(start);
                }
              
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

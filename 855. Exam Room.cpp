
void adjustAnswer( int &low, int &high, int &diff, int &ans) {
    
    int possible = low + ( high - low ) / 2;
    if( diff == -1 || diff < ( possible - low ) ) {
        ans = possible;
        diff = possible - low;
    }
}


class ExamRoom {
public:
    set < int > seats;
    int total;
    ExamRoom(int N) {
        seats.clear();
        total = N - 1;
    }
    
    int seat() {
        int prev = -1, diff = -1, ans = -1;
        
        for( int place: seats ) {
            if( prev == -1 ) {
                if( place != 0 ) {
                    diff = place;
                    ans = 0;
                }
            } else {
                adjustAnswer(prev, place, diff, ans);
            }
            
            prev = place;
        }
        
        if( prev != total && prev != -1 ) {
            if( diff == -1 || diff < ( total - prev ) ) {
                ans = total;
            }
        }
        
        if( ans == -1 ) {
            seats.insert(0);
            ans = 0;
        } else {
            seats.insert(ans);
        }
        
        return ans;
    }
    
    void leave(int p) {
        auto it = seats.find(p);
        seats.erase(it);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */

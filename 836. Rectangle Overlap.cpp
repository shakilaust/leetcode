class Solution {
public:
    bool isOverLap( int aLow, int aHigh, int bLow, int bHigh) {
        return min( aHigh, bHigh ) > max( aLow, bLow );
    }
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       return isOverLap(rec1[0], rec1[2], rec2[0], rec2[2] ) && isOverLap(rec1[1], rec1[3], rec2[1], rec2[3] );
    }
};

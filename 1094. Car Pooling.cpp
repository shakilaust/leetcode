class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int NX = 1005;
        int cap[ NX ] = {0};
        int sz = trips.size();
        for( int i = 0 ; i < sz ; i++ ) { 
            cap[trips[i][1]] += trips[i][0];
            cap[trips[i][2] ] -= trips[i][0];
        }
        
        
        
        for( int i = 1 ; i < NX ; i++ ) { 
            cap[i] += cap[i-1];
            if(cap[i] > capacity ) return false;
        }
        
        return true;
    }
};

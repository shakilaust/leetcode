class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int lst = -1;
        int ans = INT_MIN;
        int sz = seats.size();
        for( int i = 0 ; i < sz ; i++ ) {
           if( seats[i] ) {
               if( lst == -1 ) {
                   ans = max( i , ans );
               } else {
                   int mid = ( i - lst  ) / 2;
                   ans = max( ans, mid );
               }
               lst = i;
           } 
        }
        if( lst == -1 ) return seats.size();
        ans = max( ans, sz - lst - 1 );
        return ans;
    }
};

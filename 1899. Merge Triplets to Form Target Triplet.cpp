class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = 0, y = 0 , z = 0;
        for( vector < int > now: triplets ) {
            if( now[0] <= target[0] && now[1] <= target[1] && now[2] <= target[2] ) {
                x = max( x , now[0] );
                y = max( y, now[1] );
                z = max( z , now[2] );
            }
        }
        
        return x == target[0] && y == target[1] && z == target[2];
    }
};

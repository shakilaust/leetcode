class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sz = piles.size();
        if( sz == 0 ) return 0;
        sort( piles.begin(), piles.end() );
        int x = 0;
        int y = piles.size();
        y -= 1;
        int ans = 0;
        while( x < y - 1 ) {
            ans += piles[y-1];
            y -= 2;
            x += 1;
        }
        
        return ans;
    }
};

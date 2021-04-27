class Solution {
public:
    bool isPossible( vector< int> &inp, int h, int k) {
        int need = 0;
        for( int x: inp) {
            int add = ( x / k ) + ( x % k == 0 ? 0 : 1 );
            need += add;
            if( need > h ) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = INT_MAX;
        int ans = INT_MAX;
        while( low <= high ) {
            int mid = low + ( high - low ) / 2;
            if( isPossible( piles, h, mid ) ) {
                ans = mid;
                high = mid - 1;
             //   cout << " ans " << ans << " low " << low << " high " << high << endl;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

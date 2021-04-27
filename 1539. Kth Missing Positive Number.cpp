const int NX = 2005;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector < bool > freq( NX , false );
        for( int x: arr ) {
            freq[x] = true;
        }
        
       
        int ans = 0;
        while( k > 0) {
            ans++;
            if( freq[ans] == false ) {
                k--;
            }
        }
        return ans;
    }
};

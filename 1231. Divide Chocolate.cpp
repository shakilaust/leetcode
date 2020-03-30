

bool ok( vector< int >&inp, int mx, int divide) { 

    int sum = 0, total = 0;
    for( int i = 0 ; i < inp.size(); i++ ) {
        sum += inp[i];
        if( sum >= mx ) { 
            sum = 0;
            total++;
            if( total >= divide ) return true;
        }
    }
        
    return false;
}


class Solution {
public:
    int maximizeSweetness(vector<int>& inp, int K) {
        int sum = 0;
        for( int i = 0 ; i < inp.size(); i++ ) { 
            sum += inp[i];
        }

        int low = 0, ans = 0, high = sum, mid;
        while( low <= high ) { 
            mid = ( low + high ) / 2;
            if( ok(inp, mid, K + 1 ) ) { 
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }
};

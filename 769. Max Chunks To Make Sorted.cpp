class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        bool mnFound = false, mxFound = false;
        int ans = 0;
        int possibleMn = 0, possibleMx = 0;
        int n = arr.size();
        
        for( int i = 0 ; i < n ; i++ ) { 
            if( arr[i] == possibleMn ) { 
                mnFound = true;
            }
            int tmpMx  = max( i , arr[i] );
            possibleMx = max( tmpMx, possibleMx );
            if( possibleMx == i ) { 
                mxFound = true;
            }
                
            if( mxFound && mnFound ) { 
                ans++;
                mxFound = false;
                mnFound = false;
                possibleMx = i + 1;
                possibleMn = i + 1;
            }
        }
        
        return ans;
    }
};


const long mod = 1e9 + 7;
const long m = 31;
vector < int > nums;

bool isRepeatSubstringPossible(int L) { 

    long h = 0;
    for( int i = 0 ; i < L ; i++ ) {
        h = ( h*m + nums[i] )%mod;
    }

    unordered_map< long, bool > seen;
    long mx = 1;
    for( int i = 1;  i <= L ; i++ ) mx = ( mx*m )%mod;
    seen[h] = true;
    for( int start = 1 ; start < nums.size() - L + 1 ; start++ ) {

        h = (h*m - nums[start-1]*mx % mod + mod )%mod;
        h = ( h + nums[start+L - 1])%mod;
        if( seen[h] ) return true;
        seen[h] = true;
    }
    
    return false;

}

class Solution {
public:
    int longestRepeatingSubstring(string S) {
        int sz = S.size();
        nums.clear();
        for( int i = 0 ; i < sz ; i++ ) nums.push_back(S[i] - 'a');
        int low = 1, high = sz, ans = 0;
        while( low <= high ) { 
            int mid = ( low + high ) / 2;
            if(isRepeatSubstringPossible(mid)) { 
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;

        }
        return ans;
        
    }
};

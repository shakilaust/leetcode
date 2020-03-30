const long mod = 1e9 + 7;
const long m = 31;
vector < int > nums;
bool isPossible(vector< int > &startingIdxs, int startIdx, int L ) { 

     for( int i = 0 ; i < startingIdxs.size() ; i++ ) { 

        int x = startingIdxs[i];
        int y = startIdx;
        bool ok = true;
        int k = L;
        while( ok && k ) { 
            if(nums[x] != nums[y] ) ok = false;
            k--;
            x++;
            y++;
        }
         if( ok ) return true;
    }
    
    
    return false;

}
int isRepeatSubstringPossible(int L) { 

    long h = 0;
    for( int i = 0 ; i < L ; i++ ) {
        h = ( h*m + nums[i] )%mod;
    }

    unordered_map< long, vector < int > > seen;
    long mx = 1;
    for( int i = 1;  i <= L ; i++ ) mx = ( mx*m )%mod;
    seen[h].push_back(0);
    for( int start = 1 ; start < nums.size() - L + 1 ; start++ ) {

        h = (h*m - nums[start-1]*mx % mod + mod )%mod;
        h = ( h + nums[start+L - 1])%mod;
        if( seen[h].size() > 0 ) { 
            if(isPossible(seen[h], start, L) ) return start;
        }
        seen[h].push_back(start);
    }
    
    return -1;

}

class Solution {
public:
    string longestDupSubstring(string S) {
        int sz = S.size();
        nums.clear();
        for( int i = 0 ; i < sz ; i++ ) nums.push_back(S[i] - 'a');
        int low = 1, high = sz, ans = 0;
        while( low <= high ) { 
            int mid = ( low + high ) / 2;
            if(isRepeatSubstringPossible(mid)!=-1) { 
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;

        }
        
        return ans == 0 ? "" : S.substr(isRepeatSubstringPossible(ans), ans);
        
    }
};

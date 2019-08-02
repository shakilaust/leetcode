class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector < int > lmx, lmn, rmx, rmn;
        int sz = nums.size();
        int ans = nums[0] ;    
        for( int i = 0 ; i < sz ; i++ ) { 
            lmx.push_back(nums[i]);
            lmn.push_back(nums[i]);
            rmx.push_back(nums[i]);
            rmn.push_back(nums[i]);
        }


        int comunitative = nums[0];
       
        for( int i = 1 ; i < sz ; i++ ) { 
            ans = max( ans , lmx[i-1] * nums[i]);
            ans = max( ans, lmn[i-1] * nums[i] );
            if(comunitative) {
                comunitative = comunitative * nums[i];
            } else {
                comunitative = nums[i];
            }
            ans = max( ans , nums[i] );
            ans = max( ans , comunitative);

            lmx[i] = max( lmx[i], lmx[i-1] * nums[i]);
            lmn[i] = min( lmn[i], lmn[i-1] * nums[i]);
        }
        
       

        comunitative = nums[sz-1];
        for( int i = sz - 2 ; i >= 0 ; i-- ) { 
            ans = max( ans ,rmx[i+1] * nums[i]);
            ans = max( ans, rmn[i+1] * nums[i] );
            
            if(comunitative) {
                comunitative = comunitative * nums[i];
            } else {
                comunitative = nums[i];
            }
            ans = max( ans , comunitative);

            rmx[i] = max( rmx[i], rmx[i+1] * nums[i]);
            rmn[i] = min( rmn[i], rmn[i+1] * nums[i]);

        }
        return ans;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector < int > ans( sz , 0 );
        vector < int > left( sz, 0 );
        vector < int > right( sz, 0 );
        left[0] = nums[0];
        right[sz - 1 ] = nums[sz-1];
        for( int i = sz - 2 ; i >= 0 ; i-- ) { 
            right[i] = nums[i] * right[i+1];
        }
        
        for( int i = 1 ; i < sz ; i++ ) { 
            left[i] = nums[i] * left[i-1];

        }
        
        for( int i = 0 ; i < sz ; i++ ) { 
            ans[i] = ( i - 1 >= 0 ? left[i-1] : 1 ) * ( i + 1 < sz ? right[i+1] : 1 );
          //  cout << i  << " left " << left[i] << " rgt " << right[i] << endl;
        }
        

        
        
        
        
        
        return ans;
    }
};

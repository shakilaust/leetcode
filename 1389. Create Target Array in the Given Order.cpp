class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int sz = nums.size();
        vector < int > ans( sz, 0 );
     
    
        for( int i = 0; i < sz ; i++ ) { 
          int target = index[i];
          for( int j = sz - 1 ; j > target ; j-- ) { 
              ans[j] = ans[j-1];
          }
          ans[target] = nums[i];
        }
        
      
        return ans;
       
        
    }
};

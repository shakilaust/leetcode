class Solution {
public:
    int trap(vector<int>& height) {
        int sz = height.size();
        int lft_mx = 0, rgt_mx = 0;
        int ans = 0;
        int lft = 0, rgt = sz - 1;
        while( lft < rgt ) { 

            if(height[lft] < height[rgt] ) { 
                height[lft] >= lft_mx ? ( lft_mx = height[lft] ) : ans += ( lft_mx - height[lft]);
                lft++;

            } else { 
                height[rgt] >= rgt_mx ? ( rgt_mx = height[rgt] ) : ans += ( rgt_mx - height[rgt]);
                rgt--;

            }

        }
        return ans;
        
        
    }
};

/* 


*/ 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        vector < int > left(sz), right(sz), nextMx(sz);
        int mxIdx = 0;
        left[0] = 0;
        nextMx[0] = 1;
        int possibleLeft = 0; 
        for( int i = 1 ; i < sz ; i++ ) {
            
            possibleLeft = 0;
            while(height[i] > height[possibleLeft] ) { 
               possibleLeft = nextMx[possibleLeft];
            }
            left[i] = possibleLeft;
            nextMx[i] = i + 1;
        }
        mxIdx = sz - 1;
        right[ sz - 1 ] = sz - 1;
        int possibleRight = sz - 1;
        int ans = ( right[ sz - 1 ] - left[ sz - 1]  ) * height[ sz - 1];
        //printf("%d %d\n",sz - 1, ans);
        nextMx[ sz - 1 ] = sz - 2;
        for( int i = sz - 2 ; i >= 0 ; i-- ) { 
            possibleRight = sz - 1;
            while(height[i] > height[possibleRight]) { 
                possibleRight = nextMx[possibleRight];
            }
            
            right[i] = possibleRight;
            
            ans = max( ans, ( right[i] - left[i]) * height[i] );
            nextMx[i] = i - 1;

          //   printf("%d %d\n",i, ans);
        }
        
        return ans;
        
    }
};

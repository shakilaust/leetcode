class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) <= 2:
            return 0
        
        ans = 0
        
        sz = len(height)
        left_mx = [0] * sz
        right_mx = [0] * sz
        left_mx[0] = height[0]
        for i in range( 1 , sz ):
            left_mx[i] = max( left_mx[i-1], height[i])
        
        right_mx[sz-1] = height[sz - 1]
        for i in range(sz - 2, -1, -1 ):
            right_mx[i] = max( right_mx[i+1], height[i])
        
        for i in range(i, sz - 1):
            ans += min( left_mx[i], right_mx[i] ) - height[i];
        
        return ans
            

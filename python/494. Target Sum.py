

class Solution:

    
    
        
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        def DP(pos, so_far, cache = {} ):
            if pos == len(nums):
                return 1 if so_far == S else 0
            if (pos, so_far ) not in cache:
                cache[(pos, so_far)] = DP( pos + 1 , so_far + nums[pos] ) + DP( pos + 1 , so_far - nums[pos] )
                return cache[(pos, so_far)]
            return cache[(pos, so_far)]
        
        return DP( 0 , 0 )

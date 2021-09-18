class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1] * n
        dp[0] = 0
        
        for idx in range(0, n):
            mx_jump = min( n - 1 , idx + nums[idx] )
            while mx_jump > idx:
                if dp[mx_jump] == -1:
                    dp[mx_jump] = dp[idx] + 1
                elif dp[mx_jump] > dp[idx] + 1:
                    dp[mx_jump] = dp[idx] + 1
                else:
                    break
                mx_jump = mx_jump - 1
        
        return dp[n-1]

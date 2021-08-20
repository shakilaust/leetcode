class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        
        """
        
   
        ans = 0
        sz = len(s)
        
        for i in range(sz):
            left = i
            right = i + 1
            ans += 1 # each character is a palindrome
            while left >= 0 and right < sz: # calculating even length substring palindrome
                if s[left] == s[right]:
                    left -= 1
                    right += 1
                    ans += 1
                else:
                    break
            
            left = i - 1
            right = i + 1
            while x >= 0 and y < sz: # calcuting odd length substring palindrome
                if s[x] == s[y]:
                    x -= 1
                    y += 1
                    ans += 1
                else:
                    break
        
        return ans
        

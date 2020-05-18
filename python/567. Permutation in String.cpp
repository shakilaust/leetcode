class Solution:
    def is_ok(self, a, b):
        for idx in range(0, 26):
            if a[idx] != b[idx]:
                return False
        return True
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq1 = [0] * 26
        freq2 = [0] * 26
        for ch in s1:
            idx = ord(ch) - ord('a')
            freq1[idx] = freq1[idx] + 1
        
        low = 0
        sz = len(s1)
        ans = False
        for i, ch in enumerate(s2):
            idx = ord(ch) - ord('a')
            freq2[ idx ] = freq2[idx] + 1
            if i - low + 1 == sz:
                ans = self.is_ok(freq1, freq2)
                idx = ord(s2[low]) - ord('a')
                freq2[idx] = freq2[idx] - 1
                low = low + 1
            
            if ans:
                break
        
        return ans
            
        

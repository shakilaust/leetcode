class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        ans = ""
        sz = len(strs)
        if sz == 0:
            return ""
        if sz == 1:
            return strs[0]
        
        for i in range(len(strs[0])):
            idx = 1
            ok = True
            while idx < sz:
                if( i  >= len(strs[idx]) ):
                    ok = False
                    break
                if strs[idx][i] != strs[0][i]:
                    ok = False
                    break
                idx = idx + 1
            if ok is True:
                ans = ans + strs[0][i]
            else:
                break
                
        return ans
                    

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        self.backtrack("", ans, 0, 0, n)
        return ans
        
    def backtrack(self, path: str, ans: List[str], openParen: int, closeParen: int, n: int) -> None:
        if len(path) == n*2:
            ans.append(path)
        
        if openParen < n:
            self.backtrack(path+"(", ans, openParen + 1, closeParen, n)
        if closeParen < openParen:
            self.backtrack(path+")", ans, openParen, closeParen + 1, n)
        

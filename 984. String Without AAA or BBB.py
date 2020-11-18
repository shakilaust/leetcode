class Solution(object):
    def strWithout3a3b(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: str
        """
        
        res = ''
        while A > 0 or B > 0:
            if A == B:
                res += 'ab'
                A -= 1
                B -= 1
            elif A > B:
                add = min( 2 , A )
                for i in range(add):
                    res += 'a'
                A -= add
                add = min( 1 , B )
                for i in range(add):
                    res += 'b'
                B -= add
            else:
                add = min( 2 , B )
                for i in range(add):
                    res += 'b'
                B -= add
                add = min( 1 , A )
                for i in range(add):
                    res += 'a'
                A -= add
        
        return res

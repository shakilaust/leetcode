class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0
        
        product_of_digits = 1
        sum_of_digits = 0
        while n > 0:
            digit = n % 10
            n = n // 10
            product_of_digits = product_of_digits * digit
            sum_of_digits = sum_of_digits + digit
        
        return product_of_digits - sum_of_digits
            
        

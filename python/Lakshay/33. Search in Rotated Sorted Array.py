class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums) - 1
        def binarySearch(low, high):
            if low > high:
                return -1
            mid = low + ( high - low ) # 2 
            if nums[mid] == target:
                return mid
            else:
                if nums[low] <= nums[mid]:  # low to mid is sorted properly
                    if nums[low] <= target and target <= nums[mid]:
                        return binarySearch(low, mid - 1)
                    else:
                        return binarySearch( mid + 1, high )
                else:
                    if nums[mid] <= target and target <= nums[high]:
                        return binarySearch( mid + 1, high ) 
                    else:
                        return binarySearch( low, mid - 1 )
        
        return binarySearch( low, high )
                

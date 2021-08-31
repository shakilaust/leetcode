
class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        freq = collections.Counter(nums)
        tail = collections.Counter()
        
        for item in nums:
            if not freq[item]:
                continue
            freq[item] -= 1
            if tail[item - 1] > 0:
                tail[ item - 1] -= 1
                tail[ item ] += 1
            elif freq[ item + 1] > 0 and freq[ item + 2] > 0:
                freq[ item + 1] -= 1
                freq[ item + 2] -= 1
                tail[ item + 2] += 1
            else:
                return False
        
        return True

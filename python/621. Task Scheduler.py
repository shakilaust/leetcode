from collections import Counter
import heapq

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter_list = Counter(tasks)
        # this will converted into max heap, by default heapq converted into min heap
        max_heap = [-value for value in counter_list.values()]
        heapq.heapify(max_heap)
        
        ans = 0
        while len(max_heap) > 0:
            tasks = []
            for i in range(n + 1 ):
                if len(max_heap) > 0:
                    tasks.append(heapq.heappop(max_heap))
            
            for task in tasks:
                if task + 1 < 0:
                    heapq.heappush(max_heap, task + 1)
            
            if len(max_heap) == 0:
                ans += len(tasks)
            else:
                ans += ( n + 1 )
                
        
        return ans

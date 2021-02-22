class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        if( k == 1 || nums.length == 0 ) return nums;
        Deque<Integer> dq = new ArrayDeque<Integer>();
        for( int i = 0 ; i < nums.length; i++ ) {
            if( !dq.isEmpty() && dq.peekFirst() == i - k ) dq.removeFirst();
            while(!dq.isEmpty() && nums[i] > nums[dq.peekLast()] ) {
                dq.removeLast();
            }
            dq.addLast(i);
            if( i >= k - 1 ) {
                ans.add(nums[dq.peek()]);
            }
        }
        int[] res = new int[ans.size()];
      
        for( int i = 0 ; i < ans.size() ; i++ ) {
            res[i] = ans.get(i);
        }
        return res;
        
    }
}

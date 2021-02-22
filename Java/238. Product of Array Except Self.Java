class Solution {
    public int[] productExceptSelf(int[] nums) {
        int len = nums.length;
        int[] rightMul = new int[len + 1 ];
        int[] answer = new int[len];
        rightMul[len] = 1;
        for( int i = len - 1 ; i >= 0 ; i-- ) {
            rightMul[i] = rightMul[i + 1 ] * nums[i];
        }
        
        int leftMul = 1;
        for( int i = 0 ; i < len ; i++ ) {
            answer[i] = leftMul * rightMul[i + 1 ];
            leftMul = leftMul * nums[i];
        }
        
        return answer;
        
    }
}

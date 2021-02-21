class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> answer = new ArrayList<>();
        Arrays.sort(nums);
        int len = nums.length;
        for( int i = 0 ; i < len ; i++ ) {
            if( i > 0 && nums[i] == nums[i-1] ) continue;
            int low = i + 1;
            int high = len - 1;
            while( high > low ) {
                if( high + 1 < len && nums[high] == nums[high+1] ) high--;
                else if( nums[low] + nums[high] + nums[i] < 0 ) low++;
                else if( nums[low] + nums[high] + nums[i] > 0 ) high--;
                else {
                    answer.add(Arrays.asList(nums[i], nums[low], nums[high]));
                    low++;
                    high--;
                }
            
            
            }
        }
        return answer;
        
    }
}

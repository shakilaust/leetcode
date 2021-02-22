class Solution {
  
   public void solve(int[] candidates, int sum, List<List<Integer>> res, List<Integer> now, int startIdx) {
       
       if( sum == 0 ) {
           res.add( new ArrayList<>(now));
           return;
       }
       
       for( int i = startIdx ; i < candidates.length ; i++ ) {
           if( sum - candidates[i] >= 0 ) {
               now.add(candidates[i]);
               solve(candidates, sum - candidates[i], res, now, i );
               now.remove( now.size() - 1 );
           }
        }
   }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        List<Integer> now = new ArrayList<>();
        solve(candidates, target, answer, now, 0 );
        return answer;
    }
}

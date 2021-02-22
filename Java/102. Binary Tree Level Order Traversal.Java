/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
       
        List<List<Integer>> answer = new ArrayList<List<Integer>>();
        if( root == null ) return answer;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int idx = 0;
        while(!q.isEmpty()) {
            int sz = q.size();
            answer.add(new ArrayList<> ());
            while( sz-- > 0 ) {
                TreeNode now = q.poll();
                answer.get(idx).add(now.val);
                if( now.left != null ) {
                    q.add( now.left );
                }
                if( now.right != null ) {
                    q.add( now.right );
                }
            }
            idx++;
        }
        return answer;
    }
}

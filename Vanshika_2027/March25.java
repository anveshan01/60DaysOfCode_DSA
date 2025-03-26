//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if(root==null || root.val == p.val || root.val == q.val){
            return root;
        }
        TreeNode leftLCA = lowestCommonAncestor(root.left,p,q);
        TreeNode rightLCA = lowestCommonAncestor(root.right,p,q);
        if(leftLCA == null) return rightLCA;
        if(rightLCA == null) return leftLCA;
        return root;
    }
}
//https://leetcode.com/problems/binary-tree-right-side-view/
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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        rightView(root,ans,0);
        return ans;
    }
    public void rightView(TreeNode curr, List<Integer> ds, int cd){
        if(curr==null) return;
        if(cd==ds.size()) ds.add(curr.val);
        rightView(curr.right, ds, cd+1);
        rightView(curr.left, ds, cd+1);
    }
}
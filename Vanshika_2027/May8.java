// https://leetcode.com/problems/path-sum
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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root==null) return false;

        //leaf node
        if (root.left==null && root.right==null) {
            return (targetSum == root.val);
        }
        //left or right
        int sum = targetSum-root.val;
        return (hasPathSum(root.left, sum) || hasPathSum(root.right,sum));
    }
}
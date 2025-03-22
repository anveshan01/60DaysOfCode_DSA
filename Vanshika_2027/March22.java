//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
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
    class Info{
        boolean isBST;
        int min;
        int max;
        int sum;
        Info(boolean isBST,int min,int max,int sum){
            this.isBST = isBST;
            this.min = min;
            this.max = max;
            this.sum = sum;
        }
    }
    public int maxSum =0;
    public int maxSumBST(TreeNode root) {
        largestBST(root);
        return maxSum;
    }
    public Info largestBST(TreeNode root){
        if(root == null){
            return new Info(true, Integer.MAX_VALUE,Integer.MIN_VALUE,0);
        }
        Info leftInfo = largestBST(root.left);
        Info rightInfo = largestBST(root.right);

        int min = Math.min(root.val, Math.min(leftInfo.min, rightInfo.min));
        int max = Math.max(root.val, Math.max(leftInfo.max, rightInfo.max));

        if(leftInfo.isBST && rightInfo.isBST && root.val>leftInfo.max && root.val<rightInfo.min){
            int sum = root.val + leftInfo.sum + rightInfo.sum;
            maxSum = Math.max(maxSum,sum);
            return new Info(true,min,max,sum);
        }
        return new Info(false,min,max,0);
    }
}

//https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

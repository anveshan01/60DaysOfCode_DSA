// https://leetcode.com/problems/maximum-width-of-binary-tree/
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
        TreeNode node;
        int ind;

        Info(TreeNode node, int ind){
            this.node = node;
            this.ind = ind;
        }
    }

    public int widthOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(root,0));
        int maxW = 0;

        while(!q.isEmpty()){
            int n = q.size();
            int minInd = q.peek().ind;
            int first =0, last =0;

            for(int i =0; i<n;i++){
                Info curr = q.poll();
                TreeNode node = curr.node;
                int currInd = curr.ind-minInd;

                if(i==0) first = currInd;
                if(i==n-1) last = currInd;

                if(node.left !=null){
                    q.offer(new Info(node.left, 2*currInd+1));
                }
                if(node.right !=null){
                    q.offer(new Info(node.right, 2*currInd+2));
                }
                maxW = Math.max(maxW, last-first+1);
            }
        }
        return maxW;
    }
}
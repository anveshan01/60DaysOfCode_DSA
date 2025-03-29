// https://leetcode.com/problems/diameter-of-binary-tree/submissions/1590376352/
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
    public int dia =Integer.MIN_VALUE;
    public int diameterOfBinaryTree(TreeNode root) {
        diameter(root);
        return dia;
    }
    public int diameter(TreeNode root){
        if(root==null) return 0;

        int left = diameter(root.left);
        int right = diameter(root.right);
        dia = Math.max(dia, left+right);
        return  1+ Math.max(left,right);
    }
}

//https://leetcode.com/problems/summary-ranges/
class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        if(nums.length==0) return ans;
        int s = nums[0];
        for(int i =1; i<nums.length;i++){
            if(nums[i] != nums[i-1]+1){
                if(s == nums[i-1]){
                    ans.add(String.valueOf(s));
                }else{
                    ans.add(s+"->"+nums[i-1]);
                }
                s= nums[i];
            }
        }
        if(s==nums[nums.length-1]){
            ans.add(String.valueOf(s));
        }else{
            ans.add(s+"->"+nums[nums.length-1]);
        }
        return ans;
    }
}
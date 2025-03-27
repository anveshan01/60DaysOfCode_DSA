//https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
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
    public void flatten(TreeNode root) {
        TreeNode curr = root;
        while(curr!=null){
            if(curr.left!=null){
                TreeNode prev = curr.left;
                while(prev.right!=null){
                    prev = prev.right;
                }
                prev.right = curr.right;
                curr.right = curr.left;
                curr.left = null;
            }
            curr=curr.right;
        }
    }
}

//https://leetcode.com/problems/destination-city/
class Solution {
    public String destCity(List<List<String>> paths) {
        HashSet<String> cityA = new HashSet<>();
        for(List<String> path : paths){
            cityA.add(path.get(0));
        }
        for(List<String> path : paths){
            if(!cityA.contains(path.get(1))){
                return path.get(1);
            }
        }
        return "";
    }
}

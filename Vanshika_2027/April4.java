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
    public Pair<TreeNode, Integer> dfs(TreeNode root){
        if(root==null) return new Pair<>(root,0);

        Pair<TreeNode,Integer> left = dfs(root.left);
        Pair<TreeNode,Integer> right = dfs(root.right);
        if(left.getValue() > right.getValue()) return new Pair<>(left.getKey(), left.getValue()+1);
        else if(left.getValue() < right.getValue()) return new Pair<>(right.getKey(), right.getValue()+1);
        return new Pair<>(root, left.getValue()+1);
    }
    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfs(root).getKey();
    }
}

//https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
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
    public Pair<TreeNode, Integer> dfs(TreeNode root){
        if(root==null) return new Pair<>(root,0);

        Pair<TreeNode,Integer> left = dfs(root.left);
        Pair<TreeNode,Integer> right = dfs(root.right);
        if(left.getValue() > right.getValue()) return new Pair<>(left.getKey(), left.getValue()+1);
        else if(left.getValue() < right.getValue()) return new Pair<>(right.getKey(), right.getValue()+1);
        return new Pair<>(root, left.getValue()+1);
    }
    public TreeNode subtreeWithAllDeepest(TreeNode root) {
        return dfs(root).getKey();

    }
}

//https://leetcode.com/problems/node-with-highest-edge-score/
class Solution {
    public int edgeScore(int[] edges) {
        long[] scores = new long[edges.length];
        for(int i=0;i<scores.length;i++){
            scores[edges[i]] += i;
        }
        int maxNode =0;
        long maxScore =scores[0];
        for(int i=1;i<scores.length;i++){
            if(maxScore<scores[i]){
                maxScore = scores[i];
                maxNode = i;
            }
        }
        return maxNode;
    }
}

//https://leetcode.com/problems/operations-on-tree/
class LockingTree {
    private int[] parent;
    private int[] isLocked;
    private List<List<Integer>> children;

    public LockingTree(int[] parent) {
        this.parent = parent;
        int n = parent.length;
        isLocked = new int[n];
        Arrays.fill(isLocked,-1);

        this.children = new ArrayList<>();
        for(int i=0;i<n;i++){
            children.add(new ArrayList<>());
        }
        for(int i=1;i<n;i++){
            children.get(parent[i]).add(i); //add i to childList of ith parent
        }
    }

    public boolean lock(int num, int user) {
        if(isLocked[num]!=-1) return false;
        isLocked[num] = user;
        return true;
    }

    public boolean unlock(int num, int user) {
        if(isLocked[num]==-1 || isLocked[num] !=user) return false;
        isLocked[num]=-1;
        return true;
    }

    public boolean upgrade(int num, int user) {
        if(isLocked[num]!=-1) return false;
        int curr = num;
        while(curr!=-1){
            if(isLocked[curr]!=-1) return false;
            curr = parent[curr];
        }
        if(!hasLockedDesc(num)) return false;
        unlockDesc(num);
        isLocked[num] = user;
        return true;
    }

    private boolean hasLockedDesc(int num){
        Queue<Integer> q = new LinkedList<>(); //BFS approach
        q.add(num);
        while(!q.isEmpty()){
            int curr = q.remove();
            if(isLocked[curr]!=-1) return true;
            q.addAll(children.get(curr));
        }
        return false;
    }

    private void unlockDesc(int num){
        Queue<Integer> q = new LinkedList<>(); //BFS approach
        q.add(num);

        while(!q.isEmpty()){
            int curr = q.remove();
            isLocked[curr]=-1;
            q.addAll(children.get(curr));
        }
    }
}

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree obj = new LockingTree(parent);
 * boolean param_1 = obj.lock(num,user);
 * boolean param_2 = obj.unlock(num,user);
 * boolean param_3 = obj.upgrade(num,user);
 */
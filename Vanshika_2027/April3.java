//https://leetcode.com/problems/operations-on-tree/
class LockingTree {
    private int[] parent;
    private HashMap<Integer,Integer> lockedNodes;
    private List<List<Integer>> children;
    public LockingTree(int[] parent) {
        this.parent = parent;
        this.lockedNodes = new HashMap<>();
        this.children = new ArrayList<>();

        int n = parent.length;
        for(int i=0;i<n;i++){
            children.add(new ArrayList<>());
        }
        for(int i=1;i<n;i++){
            children.get(parent[i]).add(i); //add i to childList of ith parent
        }
    }

    public boolean lock(int num, int user) {
        if(lockedNodes.containsKey(num)) return false;
        lockedNodes.put(num,user);
        return true;
    }

    public boolean unlock(int num, int user) {
        if(!lockedNodes.containsKey(num) || lockedNodes.get(num) !=user){
            return false;
        }
        lockedNodes.remove(num);
        return true;
    }

    public boolean upgrade(int num, int user) {
        if(lockedNodes.containsKey(num)){
            return false;
        }
        if(!hasLockedDescendant(num)){
            return false;
        }
        if(hasLockedAncestor(num)){
            return false;
        }
        unlockDescendants(num);
        lockedNodes.put(num,user);
        return true;
    }

    private boolean hasLockedAncestor(int num){
        int curr = num;
        while(curr != -1){
            if(lockedNodes.containsKey(curr)){
                return true;
            }
            curr = parent[curr];
        }
        return false;
    }

    private boolean hasLockedDescendant(int num){
        Queue<Integer> q = new LinkedList<>(); //BFS approach
        q.add(num);
        while(!q.isEmpty()){
            int curr = q.remove();
            if(lockedNodes.containsKey(curr)){
                return true;
            }
            q.addAll(children.get(curr));
        }
        return false;
    }

    private void unlockDescendants(int num){
        Queue<Integer> q = new LinkedList<>(); //BFS approach
        q.add(num);

        while(!q.isEmpty()){
            int curr = q.remove();
            lockedNodes.remove(curr);
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
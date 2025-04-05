//https://leetcode.com/problems/throne-inheritance/
class ThroneInheritance {
    private String king;
    private HashMap<String , List<String>> children;
    private HashSet<String> dead;
    public ThroneInheritance(String kingName) {
        this.king = kingName;
        this.children = new HashMap<>();
        this.dead = new HashSet<>();
        children.put(kingName,new ArrayList<>());
    }

    public void birth(String parentName, String childName) {
        children.putIfAbsent(parentName,new ArrayList<>());
        children.get(parentName).add(childName);
        children.put(childName,new ArrayList<>());
    }

    public void death(String name) {
        dead.add(name);
    }

    public List<String> getInheritanceOrder() {
        List<String> order = new ArrayList<>();
        dfs(king,order);
        return order;
    }
    private void dfs(String name, List<String> order){
        if(!dead.contains(name)) order.add(name);
        for(String child : children.get(name)){
            dfs(child,order);
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */
class DisjointSet {

    public:
        vector<int> parent, size;
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
    
        int findUPar(int node) {
            if (node == parent[node]) {
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
    
            if(ulp_u==ulp_v)    return ;
            if (size[ulp_u] > size[ulp_v]) {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            } else {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    };
    
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            DisjointSet ds(n);
            unordered_map<int, int> edgeCount;
            for (auto& edge : edges) {
                ds.unionBySize(edge[0], edge[1]);
            }
            for (auto& edge : edges) {
                int ulp = ds.findUPar(edge[0]);
                edgeCount[ulp]++;
            }
            int totalcount = 0;
            for (int i = 0; i < n; i++) {
                if (ds.findUPar(i) == i) {
                    int nodecount = ds.size[i];
                    int properedges = (nodecount * (nodecount - 1)) / 2;
                    int existingedges = edgeCount[i];
                    if (properedges == existingedges) {
                        totalcount++;
                    }
                }
            }
            return totalcount;
        }
    };
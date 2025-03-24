//22-03-2025
// leetcode potd 22

class DisjointSet {  
    public: 
        vector<int> parent, size; 
        DisjointSet(int n) {
            parent.resize(n+1);
            size.resize(n+1); 
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
                size[i] = 1; 
            }
        }
        int findUPar(int node) {
            if(node == parent[node])
                return node; 
            return parent[node] = findUPar(parent[node]); 
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u); 
            int ulp_v = findUPar(v); 
            if(ulp_u == ulp_v) return; 
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v; 
                size[ulp_v] += size[ulp_u]; 
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v]; 
            }
        }
    };  
    class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& e) {
            int m = e.size();
            DisjointSet ds(n);
            vector<int> outD(n,0);
            unordered_map<int,vector<int>>mpp;
            int ans = 0; 
            for(int i = 0;i<m;i++){
                int a = e[i][0];
                int b = e[i][1];
                outD[a]++;
                
                ds.unionBySize(a,b);
            }
            for(int it = 0;it<n;it++){
                int p = ds.findUPar(it);
                if(p==it && ds.size[it]==1){
                    ans++;
                }
                else mpp[p].push_back(it); 
            }
            for(auto it:mpp){
                int par = it.first;
                vector<int>temp = it.second;
                int len = temp.size();
                int reqVal = ((len)*(len-1))/2;
                int out = 0;
                for(auto it:temp)out+=outD[it];
                if(out==reqVal)ans++;
            }
            return ans;
        }
    };
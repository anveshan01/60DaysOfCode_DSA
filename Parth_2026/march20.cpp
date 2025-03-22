class DisjointSet{
    vector<int> parent, size ;
public :
    DisjointSet(int n){
        size.resize(n+1) ;
        parent.resize(n+1) ;
        for(int i=0 ;i<=n ;i++){
            parent[i] = i ;
            size[i] = 1 ;
        }
    }

    int findUPar(int node){
        if(node==parent[node])
            return node ;
        return parent[node] = findUPar(parent[node]) ;
    }

    void unionBySize(int u, int v){
        int ulp_u = findUPar(u) ;
        int ulp_v = findUPar(v) ;
        if(ulp_u == ulp_v){
            return ;
        }
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u ;
            size[ulp_u] += size[ulp_v] ;
        }
        else{
            parent[ulp_u] = ulp_v ;
            size[ulp_v] += size[ulp_u] ;
        }
    }
} ;

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<int> cost(n) ;
        for(int i=0 ;i<n ;i++)  cost[i] = -1 ;
        DisjointSet ds(n) ;

        for(auto& edge : edges){
            int u = edge[0] ;
            int v = edge[1] ;
            int wt = edge[2] ;

            int ulp_u = ds.findUPar(u) ;
            int ulp_v = ds.findUPar(v) ;
            if(ulp_u != ulp_v){
                ds.unionBySize(ulp_u,ulp_v) ;
                int new_ulp = ds.findUPar(u) ;
                if (cost[ulp_u] == -1) cost[ulp_u] = wt;
                if (cost[ulp_v] == -1) cost[ulp_v] = wt;        
                cost[new_ulp] = cost[ulp_u] &= cost[ulp_v] ;
            }

            cost[ds.findUPar(u)] &= wt ;
        }

        vector<int> result ;
        for(auto& q  :query){
            int start = q[0] ;
            int target = q[1] ;

            int ulp_start = ds.findUPar(start) ;
            int ulp_target = ds.findUPar(target) ;

            if(ulp_start == ulp_target){
                result.push_back(cost[ulp_start]) ;
            }
            else{
                result.push_back(-1) ;
            }
        }

        return result ;
    }
};
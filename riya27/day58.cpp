class DisjointSet{  
    public:
         vector<int>parent,rank,size;
        DisjointSet(int n){
           parent.resize(n);
           rank.resize(n+1,0);
           size.resize(n+1);
           for(int i=0;i<n;i++){
               parent[i]=i;
               size[i]=1;
           }
       }
       int findulp(int node){
           if(node==parent[node]){
               return node;
           }
           return parent[node]=findulp(parent[node]);
       }
       void unionbyrank(int v,int u){
           int ulp_u=findulp(u);
           int ulp_v=findulp(v);
           if(ulp_u==ulp_v) return;
           if(rank[ulp_u]<rank[ulp_v]){
               parent[ulp_u]=ulp_v;
           }else if(rank[ulp_v]<rank[ulp_v]){
               parent[ulp_v]=ulp_u;
           }else{
               parent[ulp_u]=ulp_v;
               rank[ulp_v]++;
           }
       }
       void unionbysize(int v,int u){
           int ulp_u=findulp(u);
           int ulp_v=findulp(v);
           if(ulp_u==ulp_v)return;
           if(size[ulp_u]<size[ulp_v]){
               parent[ulp_u]=ulp_v;
               size[ulp_v]+=ulp_u;
           }else {
               parent[ulp_v]=ulp_u;
               size[ulp_u]+=ulp_v;
           }
       }
   };
   class Solution {
   public:
       vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
           int n=accounts.size();
           //forming disjoint set
           DisjointSet ds(n);
           unordered_map<string,int>mpp;
           for(int i=0;i<n;i++){
               for(int j=1;j<accounts[i].size();j++){
                   string mail=accounts[i][j];
                   if(mpp.find(mail)==mpp.end()){
                       mpp[mail]=i;
                   }else{
                       ds.unionbysize(i,mpp[mail]);
                   }
               }
           }
           //find ultimate parent
           vector<vector<string>>mergedmail(n);
           for(auto  it:mpp){
              string mail =it.first;
              int node=ds.findulp(it.second);
              mergedmail[node].push_back(mail);
           }
           //merge mail with name
           vector<vector<string>>ans;
           for(int i=0;i<n;i++){
               if(mergedmail[i].size()==0) continue;
               sort(mergedmail[i].begin(),mergedmail[i].end());
               vector<string>temp;
               temp.push_back(accounts[i][0]);
               for(auto it:mergedmail[i]){
                   temp.push_back(it);
               }
               ans.push_back(temp);
           }
          return ans; 
       }
   };
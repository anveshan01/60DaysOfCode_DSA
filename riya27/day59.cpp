class Solution {
    private:
    int timer=0;
    private:
       void dfs(int node,int parent,vector<int>&visited,int tin[],int low[],vector<vector<int>>&bridges,vector<int>adj[]){
           visited[node]=1;
           tin[node]=low[node]=timer;
           timer++;
           for(auto it:adj[node]){
               if(it==parent) continue;
               if(visited[it]==0){
                   dfs(it,node,visited,tin,low,bridges,adj);
                   low[node]=min(low[it],low[node]);
                    //node---it
                    if(low[it]>tin[node]){
                       bridges.push_back({node,it});
                    }
   
               }else{
                   low[node]=min(low[it],low[node]);
               }
           }
       }   
   public:
       vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
           vector<int>adj[n];
           for(auto it:connections){
               int u=it[0];
               int v=it[1];
               adj[u].push_back(v);
               adj[v].push_back(v);
           }
           vector<int>visited(n,0);
           int tin[n];
           int low[n];
           vector<vector<int>>bridges;
           dfs(0,-1,visited,tin,low,bridges,adj);
           return bridges;
       }
   };
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
       int N=adj.size();
    
     vector<int>dis(N,INT_MAX);
      dis[src]=0;               //initially store infinite dis
      queue<int>q;   //stores node
      q.push(src);
       while(!q.empty()){
        int node=q.front();
         q.pop();
        for(auto it:adj[node]){
             if(dis[node]+1<dis[it]){
              dis[it]=dis[node]+1;
              q.push(it);
             }
        }
       }
         vector<int>ans(N,-1);
       for(int i=0;i<N;i++){
          if(dis[i]!=INT_MAX){
            ans[i]=dis[i];
          }
        }
      return ans;
   
    }
};

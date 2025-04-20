class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
            vector<vector<pair<int,int>>>adj(n);
            for(int i=0;i<flights.size();i++){
                int u=flights[i][0];
                int v=flights[i][1];
                int w=flights[i][2];
                adj[u].push_back({v,w});
            }
            vector<int>dis(n,INT_MAX);
           queue<pair<int,pair<int,int>>>q;
           dis[src]=0;
           //stop ,node,dis
            q.push({0,{src,0}});
    
            while(!q.empty()){
                int stop=q.front().first;
                int node=q.front().second.first;
                int price=q.front().second.second;
                q.pop();
                 if(stop>k) continue;;
                for(auto it:adj[node]){
                    int n=it.first;
                    int w=it.second;
                    if(price+w<dis[n] && stop<=k){
                        dis[n]=price+w;
                        q.push({stop+1,{n,price+w}});
                        
                    }
                }
            }
            if(dis[dst]==INT_MAX) return -1;
            return dis[dst];
        }
    };
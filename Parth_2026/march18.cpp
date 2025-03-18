class Solution {
    public:
        void dfs(int node,int parent,vector<int>& vis,vector<vector<int>>& adj, int tin[], int low[],vector<vector<int>>& bridges,int timer){
            vis[node]=1 ;
            tin[node]=low[node]=timer ;
            timer++ ;
            for(auto it :adj[node]){
                if(it==parent){
                    continue ;
                }
                if(!vis[it]){
                    dfs(it,node,vis,adj,tin,low,bridges,timer) ;
                    low[node] = min(low[it],low[node]) ;
                    if(low[it] > tin[node]){
                        bridges.push_back({it,node}) ;
                    }
                }
                else{
                    low[node] = min(low[node],low[it]) ;
                }
            }
        }
    
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
            int timer=1 ;
            for(auto it :connections){
                int u = it[0] ;
                int v = it[1] ;
                adj[u].push_back(v) ;
                adj[v].push_back(u) ;
            }
            vector<int> vis(n,0) ;
            int tin[n] ;
            int low[n] ;
            vector<vector<int>> bridges ;
            dfs(0,-1,vis,adj,tin,low,bridges,timer) ;
            return bridges ;
        }
    };

    class Solution {
        public:
            int longestNiceSubarray(vector<int>& nums) {
                int n = nums.size();
                int left = 0;
                int right = 0;
                int maxlen = 0;
                int xor_sum = 0;
                int curr_sum = 0;
                while (right < n) {
                    curr_sum += nums[right];
                    xor_sum ^= nums[right];
                    while (xor_sum != curr_sum) {
                        curr_sum -= nums[left];
                        xor_sum ^= nums[left];
                        left++;
                    }
                    maxlen = max(maxlen, right - left + 1);
                    right++;
                }
                return maxlen;
            }
        };
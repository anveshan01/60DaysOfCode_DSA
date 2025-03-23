class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int,int>>> adj(n);
            for(auto it : roads){
                adj[it[0]].push_back({it[1], it[2]});
                adj[it[1]].push_back({it[0], it[2]});
            }
    
            const int mod = 1e9 + 7;
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;//min-heap
            vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n, 0);
    
            dist[0] = 0;
            ways[0] = 1;
            pq.push({0, 0}); // {distance, node}
    
            while (!pq.empty()) {
                auto p = pq.top();
                pq.pop();
                long long d = p.first;
                int node = p.second;
    
                if (d > dist[node]) continue; 
    
                for (auto it : adj[node]) {
                    int adjNode = it.first;
                    int edgeWeight = it.second;
    
                    if (d + edgeWeight < dist[adjNode]) {
                        dist[adjNode] = d + edgeWeight;
                        pq.push({dist[adjNode], adjNode});
                        ways[adjNode] = ways[node];
                    } 
                    else if (d + edgeWeight == dist[adjNode]) {
                        ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                    }
                }
            }
    
            return ways[n - 1] % mod;
        }
    };
    
class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            const int MOD=1e9+7;
            //adjacency list
            vector<vector<pair<int,int>>>graph(n);
            for(auto&road:roads){
                int start=road[0] ,end=road[1],time=road[2];
                graph[start].emplace_back(end,time);
                graph[end].emplace_back(start,time);
            }
            //min heap
            priority_queue<pair<long long ,int>,vector<pair<long long,int>>,greater<>>q;
            //store shortest time to reach ech node
            vector<long long>shortestTime(n,LLONG_MAX);
            //ways to reach destination
            vector<long long>pathcount(n,0);
            shortestTime[0]=0; //intinal time is zero
            pathcount[0]=1;   //one way to reach first node
            q.emplace(0,0); //{time,node}
            while(!q.empty()){
                long long currtime=q.top().first;
                int currnode=q.top().second;
                q.pop();
                //if curr time is greater than shortest time
                if(currtime>shortestTime[currnode]) continue;
                for(auto &[neighbournode,roadtime]:graph[currnode]){
                    //new shortest path
                    if(currtime+roadtime<shortestTime[neighbournode]){
                        shortestTime[neighbournode]=currtime+roadtime;
                        pathcount[neighbournode]=pathcount[currnode];
                       q.emplace(shortestTime[neighbournode],neighbournode);
                    }else if(currtime+roadtime==shortestTime[neighbournode]){
                        pathcount[neighbournode]=(pathcount[neighbournode]+pathcount[currnode])%MOD;
                    }
                    
                }
            }
    
          return pathcount[n-1];
            
        }
    };
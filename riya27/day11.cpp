class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            //initialize a adjacency list
            vector<vector<int>>graph(n);
            //to store frequncy of each adjaceny list
            unordered_map<string,int>componentfreq;
            //initialize al with self loop
            for(int i=0;i<n;i++){
                graph[i].push_back(i);
            }
            //al form edges
            for(const auto&edge:edges){
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
                }
           //store frequency of each unique al
           for(int i=0;i<n;i++){
            vector<int>neighbour=graph[i];
            sort(neighbour.begin(),neighbour.end());
            //convert to string to hash
            string key;
            for(int num:neighbour){
                key+=to_string(num)+',';
            }
            componentfreq[key]++;
           }
           //to count unique al
           int answer=0;
           for(auto it:componentfreq){
            int size=count(it.first.begin(),it.first.end(),',');
            if(size==it.second){
                answer++;
            }
           }
           return answer;
            
        }
    };
class Solution {
    public:
        void bfs(int i, int j, vector<int>& answer, vector<int>& queries, int m, int n,vector<vector<int>>& grid) {
            // up right down left
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
    
            // pair{ query , originalIdx }
            vector<pair<int,int>> sorted ;
            for(int idx = 0 ; idx < queries.size() ;idx++){
                sorted.push_back({queries[idx],idx}) ;
            }
            sort(begin(sorted),end(sorted)) ;
    
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq ;
    
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            
            int points = 0 ;
            pq.push({grid[0][0],{0,0}}) ;
            visited[0][0] = true ;
            for(auto it : sorted){
                while(!pq.empty() && pq.top().first < it.first){
                    auto [cellValue,pos] = pq.top() ;
                    pq.pop() ;
                    int r = pos.first;
                    int c = pos.second ;
                    points++;
    
                    for (int k=0 ;k<4 ;k++){
                        int newr = r + dx[k] ;
                        int newc = c + dy[k] ;
    
                        if(newr>=0 && newr<m && newc>=0 && newc<n && !visited[newr][newc] ){
                            pq.push({grid[newr][newc],{newr,newc}}) ;
                            visited[newr][newc]=true ;
                        }
                    }
                }
                answer[it.second] = points ;
            }
        }
    
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int m = grid.size();
            int n = grid[0].size();
            vector<int> answer(queries.size(), 0);
            bfs(0,0,answer, queries,m,n,grid);
            return answer;
        }
    };
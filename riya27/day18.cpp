class Solution {
    public:
        vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
            int n=grid.size();
            int m=grid[0].size();
            vector<int>ans(queries.size(),0);
            //visited
            vector<vector<bool>>visited(n,vector<bool>(m,false));
            vector<pair<int,int>>sortedquery;
            //right down left up 
            vector<pair<int,int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
            for(int i=0;i<queries.size();i++){
               sortedquery.push_back({queries[i],i});
            }
            sort(sortedquery.begin(),sortedquery.end());
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
            //top-left element
            int totalcount=0;
            
            q.push({grid[0][0],{0,0}});
            visited[0][0]=true;
            for(auto [queryval,queryindes]:sortedquery){
                while(!q.empty() && q.top().first<queryval){
                    auto [cellval,pos]=q.top();
                    int row=pos.first;
                    int col=pos.second;
                    q.pop();
                    totalcount++;
                    for(auto [r,c]:directions){
                        int nrow=row+r;
                        int ncol=col+c;
                        if(nrow>=0 &&nrow<n && ncol>=0 && ncol<m
                        && !visited[nrow][ncol] ){
                            visited[nrow][ncol]=true;
                            q.push({grid[nrow][ncol],{nrow,ncol}});
                        }
                    }
                }
                ans[queryindes]=totalcount;
            }
            return ans;
        }
    };
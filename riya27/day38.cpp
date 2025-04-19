class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int n=heights.size();
            int m=heights[0].size();
            vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,   greater<pair<int,pair<int,int>>>>q;
            q.push({0,{0,0}});
            dis[0][0]=0;
            int drow[]={-1,0,+1,0};
            int dcol[]={0,1,0,-1};
            while(!q.empty()){
                int diff=q.top().first;
                int row=q.top().second.first;
                int col=q.top().second.second;
                q.pop();
                if(row==n-1 && col==m-1) return diff;
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int newEffort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                        if(newEffort<dis[nrow][ncol]){
                           dis[nrow][ncol]=newEffort; 
                          q.push({dis[nrow][ncol],{nrow,ncol}});
                        }
                        
                    }
                }
            }
            return 0;
        }
    };
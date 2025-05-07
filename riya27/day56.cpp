class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n=moveTime.size();
            int m=moveTime[0].size();
            int ans=0;
            vector<int>drow={0,-1,0,+1};
            vector<int>dcol={-1,0,+1,0};
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
            q.push({0,0,0});
            moveTime[0][0]=0;
            vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
            dis[0][0]=0;//
            while(!q.empty()){
                int row=q.top()[1];
                int col=q.top()[2];
                int time=q.top()[0];
                q.pop();
               
                if(row==n-1 && col==m-1) return time;
                 if(time>dis[row][col]) continue;
                
                for(int i=0;i<4;i++){
                    int nrow=drow[i]+row;
                    int ncol=dcol[i]+col;
            
                    if(nrow<n && nrow>=0 && ncol>=0 && ncol<m ){
                       int dist=max(time,moveTime[nrow][ncol])+1;
                       if(dist<dis[nrow][ncol]){
                        dis[nrow][ncol]=dist;
                        q.push({dist,nrow,ncol});
                       }
                    }
                }
            }
            return -1;
    
        }
    };
        
    
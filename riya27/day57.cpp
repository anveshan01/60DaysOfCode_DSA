lass Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n=moveTime.size();
            int m=moveTime[0].size();
            int ans=0;
            vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
            q.push({0,0,0});
            dis[0][0]=0;
            moveTime[0][0]=0;
            vector<int>drow={0,-1,0,+1};
            vector<int>dcol={-1,0,+1,0};
            while(!q.empty()){
                int time=q.top()[0];
                int row=q.top()[1];
                int col=q.top()[2];
                q.pop();
                if(row==n-1 && col==m-1) return time;
                if(time>dis[row][col]) continue;
                for(int i=0;i<4;i++){
                    int nrow=drow[i]+row;
                    int ncol=dcol[i]+col;
                    if(nrow>=0 && nrow<n &&
                    ncol>=0 && ncol<m){
                        int cost=max(time,moveTime[nrow][ncol]);
                        if((nrow+ncol)%2 ==0){
                            cost=cost+2;
    
                        }else{
                            cost++;
                        }
                        if(cost<dis[nrow][ncol]){
                            dis[nrow][ncol]=cost;
                            q.push({cost,nrow,ncol});
                        }
                    }
                }
            }
            return -1;
        }
    };
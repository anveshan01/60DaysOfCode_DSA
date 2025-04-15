class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
      vector<vector<int>>dist(n,vector<int>(m,1e9));
      queue<pair<int,pair<int,int>>>q;  //dis,(row,col)
      q.push({1,{0,0}});
      dist[0][0]=1;
      vector<vector<int>>dir={{1,0},{0,1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1},{0,-1}};
      while(!q.empty()){
        int dis=q.front().first;
        int row=q.front().second.first;
        int col=q.front().second.second;
        q.pop();
         if(row==n-1 && col==n-1) return dis;
        for(int i=0;i<8;i++){
            int drow=row+ dir[i][0];
            int dcol=col+dir[i][1];
            if(drow>=0 && drow<n && dcol>=0 && dcol<m &&
            grid[drow][dcol]==0 && dis+1<dist[drow][dcol]){
                dist[drow][dcol]=dis+1;
               
                q.push({dis+1,{drow,dcol}});
            }
        }
      }
     // int k=dis.size();
      return -1;
    }
};
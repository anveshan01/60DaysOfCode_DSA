class Solution {
    public:
      int minimumMultiplications(vector<int>& arr, int start, int end) {
          // code here
          queue<pair<int,int>>q;
          vector<int>dist(100000,1e9);
          dist[start]=0;
          q.push({start,0});
          int mod=100000;
          //0(100000 * V)
          if(start==end) return 0;
          while(!q.empty()){
              int node=q.front().first;
              int step=q.front().second;
              q.pop();
              for(auto it:arr){
                  int num=(it*node)%mod;
                  if(step+1<dist[num]){
                      dist[num]=step+1;
                      if(num==end) return step+1;
                      q.push({num,step+1});
                  }
              }
          }
          return -1;
      }
  };
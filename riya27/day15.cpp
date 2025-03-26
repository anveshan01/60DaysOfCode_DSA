class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            int n=grid.size();
            vector<int>vec;
            int m=grid[0].size();
            for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
              }
            }
            sort(vec.begin(),vec.end());
            int median=vec[vec.size()/2];
            int sum=0;
    
            for(int i=0;i<vec.size();i++){
                if(abs(median-vec[i])%x!=0){
                    return -1;
                }
            }
            
            int count=0;
            for(int i=0;i<vec.size();i++){
                count+=(abs((median-vec[i])/x));
            }
            return count;
            
        }
    };
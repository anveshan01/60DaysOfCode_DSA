class Solution {
    public:
    
        bool isPossible(int k , vector<int>& nums, vector<vector<int>>& queries){
            int n = nums.size() ;
            vector<int> sweep_line(n+1,-0) ;
            for(int i=0 ;i<k ;i++){
                sweep_line[queries[i][0]] += queries[i][2] ;
                if(queries[i][1] +1 <n){
                    sweep_line[queries[i][1] +1 ] -= queries[i][2] ;
                }
            }
            for(int i=1 ;i<=n ;i++){
                sweep_line[i]+=sweep_line[i-1] ;
            }
            int flag  =1 ;
            for(int i=0 ;i<n ;i++){
                if(sweep_line[i] < nums[i]){
                    flag = 0 ;
                }
            }
    
            return flag == 1 ? true : flag ;
        }
    
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int n = queries.size() ;
            int low =0 ;
            int high = n ;
            int ans = -1 ;
            while(low<=high){
         // binary search on K since it can be 0 to n .K will be in a monotonic predicate state
                int mid =  low + (high-low)/2 ;
                if(isPossible(mid,nums,queries)){
                    high = mid-1 ;
                    ans = mid ;
                }
                else{
                    low = mid +1 ;
                }
            }
            return ans ;
        }
    };
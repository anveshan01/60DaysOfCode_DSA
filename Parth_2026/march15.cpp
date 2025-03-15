class Solution {
    public:
    
        bool canAssign(int capability, vector<int>& nums, int k){
            int count = 0;
            for(int i=0 ; i<nums.size() ;i++){
                if(nums[i]<=capability){
                    count++ ;
                    i++ ;
                }
            }
            return count >= k ;
        }
    
        int minCapability(vector<int>& nums, int k) {
            int low = *min_element(begin(nums),end(nums)) ;
            int high = *max_element(begin(nums),end(nums)) ;
            int mid ;
            int ans = -1 ;
            while(low<=high){
                mid = low + (high-low)/2 ;
                if(canAssign(mid,nums,k)){
                    ans = mid ;
                    high = mid-1 ;
                }
                else{
                    low = mid+1 ;
                }
            }
            return ans ;
        }
    };
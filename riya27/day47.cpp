class Solution {
    public:
        long long countSubarrays(vector<int>& nums, long long k) {
            long long ans=0;
            int n=nums.size();
            int left=0;
            int right=0;
            long long sum=0;
            while(right<n){
                     
                         sum+=nums[right];
                     
                     while((sum*(right-left+1) )>=k){
                        sum-=nums[left];
                        left++;
                     }
                    ans+=(right-left+1);
                    right++;
    
                
            }
            return ans;
        }
    };
class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long long ans=0;
            int start=-1;
            int maxi=-1,mini=-1;
            //int count=0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<minK || nums[i]>maxK) start=i;
                if (nums[i]==minK) mini=i;
                if(nums[i]==maxK) maxi=i;
                int valid=min(maxi,mini);
                if(valid>start){
                     ans+=(valid-start);
                }
               
              
            }
           return ans;
        }
    };
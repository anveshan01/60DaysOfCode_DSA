class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int count=0;
            int n=nums.size();
            int l=0;
            int r=1;
            int k=2;
            while(k<n){
                if((nums[l]+nums[k])*2==nums[r]){
                    count++;
                }
                l++;
                r++;
                k++;
            }
           return count; 
        }
    };
class Solution {
    public:
        int arrayPairSum(vector<int>& nums) {
            int maxi=0;
            sort(nums.begin(),nums.end());
            int n=nums.size();
            int j=1;
            for(int i=0;i<n-1;i=i+2){
                maxi+=min(nums[i],nums[j]);
                j=j+2;
               
    
            }
            
            return maxi;
        }
    };
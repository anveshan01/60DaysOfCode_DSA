class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int n=nums.size();
            int left=0;
            int right=0;
            int bitmask=0;  //track bits of elements
             int maxi=1;
            while(left<n &&right<n){
                if((bitmask & nums[right])==0){
                   maxi=max(maxi,right-left+1);
                   bitmask|=nums[right];  //add to bitmask
                    right++;
                }else{
                    bitmask^=nums[left];  //remove from bitmASK
                      left++;
                }
                
            }
    
            return maxi;
        }
    };
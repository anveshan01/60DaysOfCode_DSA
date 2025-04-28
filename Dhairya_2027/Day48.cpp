//27-04-2025

class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int n = nums.size();
            int count = 0;
    
            for(int i = 0 ; i <= n-3 ; i++){
                int first = nums[i];
                int second = nums[i+1];
                int third = nums[i+2];
    
                if(2*(first + third) == second){
                    count++;
                }
            }
            return count;
        }
    };
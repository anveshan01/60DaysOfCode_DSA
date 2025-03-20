// 19-03-2025
// POTD LEETCODE 19

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int n = nums.size();
            int op = 0;
    
            for(int i = 0 ; i < n ; i++){
                if(nums[i] == 0){
                    if(i <= n-3){
                        for(int j = 0 ; j < 3 ; j++){
                            nums[i+j] ^= 1;
                        }
                        op++;
                    }
                    else{
                        return -1;
                    }
                }
            }
            return op;
        }
    };
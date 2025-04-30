//30-04-2025

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count{0};
            for(int num : nums){
                int digit{static_cast<int>(log10(num)+1)};
                if(!(digit&1)) count++;
            }
            return count;
        }
    };
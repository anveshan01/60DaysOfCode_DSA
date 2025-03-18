// 18-03-2025
// POTD LEETCODE(18-03-2025)

class Solution {
    public:
        int longestNiceSubarray(vector<int>& nums) {
            int l = 0, usedBits = 0, maxLength = 0;
    
            for (int r = 0; r < nums.size(); r++) {
                while ((usedBits & nums[r]) != 0) {
                    usedBits ^= nums[l];
                    l++;
                }
    
                usedBits |= nums[r];
                maxLength = max(maxLength, r - l + 1);
            }
    
            return maxLength;
        }
    };
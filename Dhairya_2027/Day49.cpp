//28-04-2025

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int maxElement = *max_element(nums.begin(), nums.end());
            long long ans = 0, start = 0;
            int maxElementsInWindow = 0;
    
            for (int end = 0; end < nums.size(); end++) {
                if (nums[end] == maxElement) {
                    maxElementsInWindow++;
                }
                while (maxElementsInWindow == k) {
                    if (nums[start] == maxElement) {
                        maxElementsInWindow--;
                    }
                    start++;
                }
                ans += start;
            }
            return ans;
        }
    };
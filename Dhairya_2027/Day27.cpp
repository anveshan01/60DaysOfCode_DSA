//7-04-2025

class Solution {
    public:
        int t[201][20001];  // Memoization table
    
        bool solve(vector<int>& nums, int i, int x) {
            if (x == 0) {
                return true;  // Base case: sum is 0, which is always achievable
            }
            if (i >= nums.size()) {
                return false;  // No more elements to consider
            }
            if (t[i][x] != -1) {
                return t[i][x];  // Return the previously computed result
            }
    
            bool take = false;
            if (nums[i] <= x) {
                take = solve(nums, i + 1, x - nums[i]);  // Include nums[i]
            }
            bool not_take = solve(nums, i + 1, x);  // Exclude nums[i]
    
            return t[i][x] = take || not_take;  // Store result and return
        }
    
        bool canPartition(vector<int>& nums) {
            if (nums.empty()) {
                return false;  // Handle edge case: empty array
            }
    
            int n = nums.size();
            int S = accumulate(nums.begin(), nums.end(), 0);
    
            if (S % 2 != 0) {
                return false;  // If sum is odd, partition is not possible
            }
    
            memset(t, -1, sizeof(t));  // Initialize memoization table
            int x = S / 2;
    
            return solve(nums, 0, x);  // Check if it's possible to form a subset with sum S/2
        }
    };
    
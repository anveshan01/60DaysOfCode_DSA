//26-04-2025

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int, int> seen;
    
            for (int i = 0; i < nums.size(); i++) {
                if (seen.count(nums[i]) && i - seen[nums[i]] <= k) {
                    return true;
                }
                seen[nums[i]] = i;
            }
            return false;
        }
    };
    
    
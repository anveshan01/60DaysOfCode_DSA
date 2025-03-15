// 15-03-2025
//POTD 15

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    
    bool canAssign(int max_val, vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= max_val) {  // Use `<=` to allow values up to max_val
                count++;
                i++;  // Skip next house
            }
        }
        return count >= k;
    }

public:
    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canAssign(mid, nums, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

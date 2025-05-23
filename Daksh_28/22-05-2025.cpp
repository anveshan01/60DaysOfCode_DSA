// LeetCode Contest
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int s = 0;
            int x = nums[i];

            // Calculate sum of digits of nums[i]
            while (x > 0) {
                s += x % 10;
                x /= 10;
            }

            if (s == i) {
                return i;
            }
        }
        return -1;
    }
};
//T.C: O(N)
//S.C: O(1)


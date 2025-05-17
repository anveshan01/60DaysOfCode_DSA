// LeetCode 75
// Approach 3
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int num : nums) {
            if (num == 0) c0++;
            else if (num == 1) c1++;
            else c2++;
        }
        int i = 0;
        for (int j = 0; j < c0; j++) nums[i++] = 0;
        for (int j = 0; j < c1; j++) nums[i++] = 1;
        for (int j = 0; j < c2; j++) nums[i++] = 2;
    }
};
// T.C: O(n)
// S.C: O(1)
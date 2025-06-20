// LeetCode 3423
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        for(int i = 1 ; i < n + 1; i++){
            res = max(res,abs(nums[i-1] - nums[i % n]));
        }
        return res;
    }
};
// T.C: O(n)
// S.C: O(1)

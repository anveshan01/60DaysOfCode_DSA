// 2444 LeetCode
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        cin.tie(nullptr);
        cout.tie(nullptr);
        long long res = 0;
        int bad = -1, left = -1, right = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (!(minK <= nums[i] && nums[i] <= maxK))
            {
                bad = i;
            }
            if (nums[i] == minK)
            {
                left = i;
            }
            if (nums[i] == maxK)
            {
                right = i;
            }
            res += max(0, min(left, right) - bad);
        }
        return res;
    }
};
// T.C: O(n)
// S.C: O(1)
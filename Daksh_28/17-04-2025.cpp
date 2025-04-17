// 2176 LeetCode
class Solution
{
public:
    int countPairs(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if ((i * j) % k == 0 && nums[i] == nums[j])
                {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
// T.C O(n^2)
// S.C O(1)

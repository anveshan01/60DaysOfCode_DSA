// 2529 - Leetcode
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int n = 0, p = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                n++;
            }
            else if (nums[i] > 0)
            {
                p++;
            }
        }
        return max(p, n);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
// 1004 LeetCode
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int r = 0, l = 0, ze = 0, maxlen = 0;

        while (r < nums.size())
        {
            if (nums[r] == 0)
            {
                ze++;
            }
            while (ze > k)
            {
                if (nums[l] == 0)
                {
                    ze--;
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);

            r++;
        }

        return maxlen;
    }
};
// T.C. O(N)
// S.C. O(1)
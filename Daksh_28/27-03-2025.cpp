// 2780 LeetCode
class Solution
{
public:
    int minimumIndex(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        int maj = -1;
        for (auto i : nums)
        {
            if (count == 0)
            {
                maj = i;
                count = 1;
            }
            else if (maj == i)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        int majcount = 0;
        for (auto num : nums)
        {
            if (num == maj)
            {
                majcount++;
            }
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == maj)
            {
                count++;
            }
            int rem = majcount - count;
            int n1 = i + 1;
            int n2 = n - i - 1;
            if (count * 2 > n1 && rem * 2 > n2)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
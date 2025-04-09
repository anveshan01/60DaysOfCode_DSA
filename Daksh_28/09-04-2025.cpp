// LeetCode 3375
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < k)
                return -1;
            if (nums[i] == k)
                continue;

            m[nums[i]]++;
        }

        return m.size();
    }
};
// T.C O(n)
// S.C O(n)
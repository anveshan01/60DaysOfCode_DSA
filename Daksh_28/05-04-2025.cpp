// LeetCode 1863
class Solution
{
public:
    int ans = 0;

    void backtrack(int x, int idx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            ans += x;
            return;
        }
        backtrack(x ^ nums[idx], idx + 1, nums);
        backtrack(x, idx + 1, nums);
    }

    int subsetXORSum(vector<int> &nums)
    {
        backtrack(0, 0, nums);
        return ans;
    }
};

// T.C : O(2^n) (Exponential)
// S.C : O(n) (Recursion stack space)
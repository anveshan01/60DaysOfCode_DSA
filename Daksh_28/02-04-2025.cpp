// 2873 Leetcode
class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        long long m = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long value = (long long)(nums[i] - nums[j]) * nums[k];
                    m = max(m, value);
                }
            }
        }
        return (m > 0 ? m : 0);
    }
};

// T.C: O(n^3)
// S.C: O(1)

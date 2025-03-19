// 1052 LeetCode
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int n = customers.size();

        int maxunsat = 0;
        int currUnsat = 0;
        for (int i = 0; i < minutes; i++)
        {
            currUnsat += customers[i] * grumpy[i]; // 0 means satisfied to add nahi hoga
        }
        maxunsat = currUnsat;
        int i = 0;
        int j = minutes;

        while (j < n)
        { // fixed window
            currUnsat += customers[j] * grumpy[j];
            currUnsat -= customers[i] * grumpy[i];

            maxunsat = max(maxunsat, currUnsat);
            i++;
            j++;
        }
        int totalsat = maxunsat;
        for (int i = 0; i < n; i++)
        {
            totalsat += customers[i] * (1 - grumpy[i]);
        }
        return totalsat;
    }
};

// 3191 LeetCode
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int o = 0;

        for (int i = 2; i < n; i++)
        {
            if (nums[i - 2] == 0)
            {
                o++;
                nums[i - 2] ^= 1;
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
            }
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum == nums.size())
            return o;
        return -1;
    }
};
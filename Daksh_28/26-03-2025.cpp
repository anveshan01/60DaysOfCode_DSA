// 410 LeetCode
class Solution
{
public:
    int count(vector<int> &nums, int mid, int n)
    {
        int count = 0;
        int split = 1;
        for (int i = 0; i < n; i++)
        {
            if (count + nums[i] <= mid)
            {
                count += nums[i];
            }
            else
            {
                split++;
                count = nums[i];
            }
        }
        return split;
    }

    int splitArray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int split = count(nums, mid, n);
            if (split <= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// T.C. O(NlogN)
// S.C. O(1)

// 2033 LeetCode
class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> a;
        int ans = 0;

        for (int r = 0; r < grid.size(); r++)
        {
            for (int c = 0; c < grid[0].size(); c++)
            {
                a.push_back(grid[r][c]);
            }
        }

        int length = a.size();

        nth_element(a.begin(), a.begin() + length / 2,
                    a.end());

        int common = a[length / 2];

        for (int number : a)
        {
            if (number % x != common % x)
                return -1;
            ans += abs(common - number) / x;
        }

        return ans;
    }
};
// T.C. O(N^2)
// S.C. O(N^2)
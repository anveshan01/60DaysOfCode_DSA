// 3355 - LeetCode
class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &q)
    {
        int n = nums.size();
        vector<int> sum(n + 1, 0); // Difference Array
        for (auto &v : q)
        {
            sum[v[0]]--;     // v[0] = L == -1
            sum[v[1] + 1]++; // v[1]+1 = R == -1
        }
        // Prefix Sum
        int prev = 0, count = 0;
        for (int i = 0; i < n; i++)
        {
            sum[i] += prev;
            int val = nums[i] + sum[i];
            if (val <= 0)
                count++;
            prev = sum[i];
        }
        return count == n;
    }
};
// Time Complexity: O(n + q)
// Space Complexity: O(n)

// 3356 LeetCode
class Solution
{
public:
    int n, Q;

    bool checkwithDiff(vector<int> &nums, vector<vector<int>> &queries, int k)
    {
        vector<int> diff(n + 1, 0);

        for (int i = 0; i <= k; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            diff[l] += x;
            if (r + 1 < n)
                diff[r + 1] -= x;
        }

        int cum = 0;
        for (int i = 0; i < n; i++)
        {
            cum += diff[i];
            diff[i] = cum;

            if (nums[i] - diff[i] > 0)
            {
                return false;
            }
        }
        return true;
    }

    int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        n = nums.size();
        Q = queries.size();

        auto lambda = [](int x)
        { return x == 0; };
        if (all_of(nums.begin(), nums.end(), lambda))
        {
            return 0;
        }

        int low = 0, high = Q - 1, ans = -1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (checkwithDiff(nums, queries, mid))
            {
                ans = mid + 1;
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

// Time Complexity: O(n + Q)
// Space Complexity: O(n)
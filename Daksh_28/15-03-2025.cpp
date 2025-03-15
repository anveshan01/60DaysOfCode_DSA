// 213 LeetCode
class Solution
{
public:
    int t[101];
    int solve(vector<int> &nums, int i, int n)
    {
        if (i > n)
            return 0;
        if (t[i] != -1)
            return t[i];

        int take = nums[i] + solve(nums, i + 2, n);
        int skip = solve(nums, i + 1, n);

        return t[i] = max(take, skip);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        memset(t, -1, sizeof(t));

        int take_0th_house = solve(nums, 0, n - 2);

        memset(t, -1, sizeof(t));

        int take_1st_house = solve(nums, 1, n - 1);

        return max(take_0th_house, take_1st_house);
    }
};

// 2560 LeetCode
class Solution
{
public:
    int isPossible(vector<int> &nums, int mid, int k)
    {
        int house = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= mid)
            {
                house++;
                i++; // i+2
            }
        }
        return house >= k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int n = nums.size();

        int l = *min_element(begin(nums), end(nums));
        int r = *max_element(begin(nums), end(nums));

        int result = r;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (isPossible(nums, mid, k) == true)
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return result;
    }
};
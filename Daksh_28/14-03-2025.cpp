// 2226 LeetCode
class Solution
{
public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long sum = accumulate(candies.begin(), candies.end(), 0LL);
        if (sum < k)
        {
            return 0;
        }

        long long low = 1, high = *max_element(candies.begin(), candies.end());
        long long ans;

        while (low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long count = 0;

            for (int c : candies)
            {
                count += c / mid;
            }
            if (count >= k)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};
// Time Complexity: O(nlogn)
// Space Complexity: O(1)

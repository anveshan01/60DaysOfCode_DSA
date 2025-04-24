// 2799 LeetCode
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        cin.tie(0);
        cout.tie(0);
        unordered_set<int> s(nums.begin(), nums.end());
        int dis = s.size();

        if (dis == 1)
        {
            int n = nums.size();
            return n * (n + 1) / 2; // all subarrays are valid
        }

        int cnt = 0, left = 0;
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int right = 0; right < n; ++right)
        {
            freq[nums[right]]++;

            while (freq.size() == dis)
            {
                cnt += n - right;
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }

        return cnt;
    }
};

// T.C: O(n)
// S.C: O(n)

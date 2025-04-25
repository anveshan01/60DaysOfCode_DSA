// LeetCode 2845
class Solution
{
public:
    long long countInterestingSubarrays(vector<int> &nums, int mod, int k)
    {
        cin.tie(0);
        cout.tie(0);
        long long res = 0; // res can be big 100000 * 100001
        int pre = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int num : nums)
        {
            if (num % mod == k)
            {
                pre++;
            }
            int curMod = pre % mod;
            int t = (curMod - k + mod) % mod;
            res += mp[t];
            mp[curMod]++;
        }

        return res;
    }
};

// T.C: O(n)
// S.C: O(n)

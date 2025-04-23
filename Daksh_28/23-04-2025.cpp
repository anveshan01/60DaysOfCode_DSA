// 1399 LeetCode
class Solution
{
public:
    int countLargestGroup(int n)
    {
        vector<int> mp(37, 0);
        int ms = 0;

        for (int i = 1; i <= n; i++)
        {
            int sum = 0, num = i;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            mp[sum]++;
            ms = max(ms, mp[sum]);
        }
        int cnt = 0;
        for (auto &it : mp)
        {
            if (it == ms)
                cnt++;
        }
        return cnt;
    }
};
// T.C O(n)
// S.C O(1)
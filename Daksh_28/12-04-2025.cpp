// 1652 LeetCode
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> res(code.size(), 0);
        int n = code.size();
        if (k == 0)
            return res;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0;
            if (k > 0)
            {
                for (int j = 1; j <= k; ++j)
                {
                    sum += code[(i + j) % n];
                }
            }
            else if (k < 0)
            {
                for (int j = 1; j <= -k; ++j)
                {
                    sum += code[(i - j + n) % n];
                }
            }
            res[i] = sum;
        }
        return res;
    }
};
// T.C: O(n^2)
// S.C: O(n)

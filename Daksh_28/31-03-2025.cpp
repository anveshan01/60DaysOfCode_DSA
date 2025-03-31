// LeetCode 2551
class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {
        if (k == 1)
        {
            return 0;
        }

        vector<int> souble;
        for (size_t i = 0; i < weights.size() - 1; ++i)
        {
            souble.push_back(weights[i] + weights[i + 1]);
        }

        sort(souble.begin(), souble.end());

        int min = accumulate(souble.begin(), souble.begin() + (k - 1), 0);
        int max = accumulate(souble.end() - (k - 1), souble.end(), 0);

        return max - min;
    }
};
// T.C: O(nlogn)
// S.C: O(1)

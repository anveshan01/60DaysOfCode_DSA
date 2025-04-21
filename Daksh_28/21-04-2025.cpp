// 2145 LeetCode
class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        int curr = 0, maxval = 0, minval = 0;
        for (int &d : differences)
        {
            curr = curr + d;

            minval = min(minval, curr);
            maxval = max(maxval, curr);

            if ((upper - maxval) - (lower - minval) + 1 <= 0)
            {
                return 0;
            }
        }
        return (upper - maxval) - (lower - minval) + 1;
    }
};
// T.C : O(n)
// S.C : O(1)

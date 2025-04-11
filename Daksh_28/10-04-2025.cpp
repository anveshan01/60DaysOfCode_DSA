// 1837
class Solution
{
public:
    int sumBase(int n, int k)
    {
        int sum = 0;
        while (n)
        {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};
// T.C O(log n)
// S.C O(1)

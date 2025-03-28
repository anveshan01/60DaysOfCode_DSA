// 1922 LeetCode
class Solution
{
public:
    long long N = 1e9 + 7;

    long long fn(long long n, long long x)
    {
        long long res = 1;
        while (x)
        {
            if (x & 1)
                res = (res * n) % N;
            n = (n * n) % N;
            x /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n)
    {
        long long x = (n + 1) / 2, y = n / 2;

        return (fn(5, x) * fn(4, y)) % N;
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)

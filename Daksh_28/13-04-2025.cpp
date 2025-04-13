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
            if (x % 2 != 0) // if odd
                res = (res * n) % N;
            n = (n * n) % N; // eve
            x /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n)
    {
        long long x = (n + 1) / 2, y = n / 2;

        return (fn(5, x) * fn(4, y)) % N; // recursive
    }
};

// T.C = O(log n)
// S.C = O(1)
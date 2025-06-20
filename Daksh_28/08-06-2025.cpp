// LeetCode 440
class Solution {
public:
    int findKthNumber(int n, int k) {
        long long res = 1;

        for (int i = 1; i < k;) {
            long long gap = getGap(res, res + 1, n);
            if (i + gap <= k) {
                i += gap;
                ++res;
            } else {
                ++i;
                res *= 10;
            }
        }

        return static_cast<int>(res);
    }

private:
    long long getGap(long long a, long long b, int n) {
        long long gap = 0;
        while (a <= n) {
            gap += std::min(static_cast<long long>(n) + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }
};
// T.C: O(log n)
// S.C: O(1)

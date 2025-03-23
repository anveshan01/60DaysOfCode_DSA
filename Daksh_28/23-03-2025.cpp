// LeetCode 374
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1;
        int r = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int val = guess(mid);
            if (val == -0)
            {
                return mid;
            }
            else if (val == -1)
            {
                r = mid - 1;
            }
            else if (val == 1)
            {
                l = mid + 1;
            }
        }
        return -1;
    }
};
// T.C. O(logN)
// S.C. O(1)

// 1539 LeetCode
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int si = arr.size();
        int l = 0;
        int r = si;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            int m = arr[mid] - 1 - mid;
            if (k <= m)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return r + k;
    }
};
// T.C. O(logN)
// S.C. O(1)

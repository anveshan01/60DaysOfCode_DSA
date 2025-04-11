// 2843 Won't work for 10^4
class Solution
{
public:
    int countSymmetricIntegers(int low, int high)
    {
        int cnt = 0;
        for (int i = low; i <= high; i++)
        {
            if (i > 10 && i <= 99 && i % 11 == 0)
            {
                cnt++;
            }
            else if (i > 1000 && i <= 9999)
            {
                int f = i / 1000;
                int s = (i / 100) % 10;
                int t = (i / 10) % 10;
                int fr = i % 10;

                if ((f + s) == (t + fr))
                    cnt++;
            }
        }
        return cnt;
    }
};
// T.C O(n)
// S.C O(1)

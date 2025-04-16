// LeetCode 258
class Solution
{
public:
    int addDigits(int num)
    {
        if (num == 0)
        {
            return 0;
        }
        else if (num % 9 == 0)
        {
            return 9;
        }
        else
            return num % 9;
    }
};
// T.C = O(1)
// S.C = O(1)

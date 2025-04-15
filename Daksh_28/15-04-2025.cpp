// GFG Tower Of Hanoi
class Solution
{
public:
    // You need to complete this function

    int towerOfHanoi(int n, int from, int to, int aux)
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1; // main to target
        }
        // n - 1 main to aux
        int moves1 = towerOfHanoi(n - 1, from, aux, to);
        // main to target
        int moveDisk = 1;

        // n - 1 aux to target
        int moves2 = towerOfHanoi(n - 1, aux, to, from);

        return moves1 + moveDisk + moves2;
    }
};
// T.C = O(2^n)
// S.C = O(n)
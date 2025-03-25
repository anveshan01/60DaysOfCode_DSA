// 51 LeetCode
class Solution
{
public:
    int N;
    vector<vector<string>> result;
    // check on 3 things upward, left diagonal upward, right diagonal upward beacuse we are placing queens row wise.
    // upward
    bool isValid(vector<string> &board, int row, int col)
    {
        for (int i = row - 1; i >= 0; i--)
        {
            if (board[i][col] == 'Q')
            {
                return false;
            }
        }
        // left diagonal upward
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        // right diagonal upward
        for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        {
            if (board[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    void solve(vector<string> &board, int row)
    {
        if (row >= N)
        { // when we reach the last row, we have placed all the queens in the board
            result.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++)
        {
            if (isValid(board, row, col))
            {
                board[row][col] = 'Q'; // place the queen

                solve(board, row + 1);

                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        result.clear();
        N = n;
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        return result;
    }
};
// T.C. O(N!)
// S.C. O(N^2)

// 33 LeetCode
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[l] <= nums[mid])
            { // if left part is sorted
                if (nums[l] <= target && target <= nums[mid])
                { // check if target lies in left part
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            { // if right part is sorted
                if (nums[mid] < target && target <= nums[r])
                { // check if target lies in right part
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};
// T.C. O(logN)
// S.C. O(1)

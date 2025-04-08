// 37 Sudoku Solver
class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board); // call the function to solve the sudoku
    }
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[i][j] == '.') // check for the empty place
                {
                    for (char c = '1'; c <= '9'; c++)
                    { // try for all numbers from 1 to 9
                        if (isValid(board, i, j, c))
                        {
                            board[i][j] = c;

                            if (solve(board) == true) // check if the number is valid in that place or not
                            {
                                return true; // if it is valid then put the number in that place and call the function again to check for the next empty place
                            }
                            else
                                board[i][j] = '.'; // if it is not valid then try for the next number
                        }
                    }
                    return false; // if all numbers are tried and none of them is valid then return false
                }
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == c) // check for the column
            {
                return false;
            }
            if (board[row][i] == c) // check for the row
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) // check withing 3 x 3 box
                return false;
        }
        return true;
    }
};
// T.C O(9^(n => '.')
// S.C O(1)

// 3396
class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        vector<bool> tru(100);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (tru[nums[i]])
            {
                return i / 3 + 1;
            }
            tru[nums[i]] = true;
        }
        return 0;
    }
};
// T.C O(n)
// S.C O(1)
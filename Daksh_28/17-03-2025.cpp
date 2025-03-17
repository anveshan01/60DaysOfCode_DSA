// 2206 LeetCode
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

// Time Complexity: O(nlogn)(Sorting)(1 for loop)
// Space Complexity: O(1)

// 225 LeetCode
class MyStack
{
public:
    queue<int> que;
    MyStack()
    {
    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        if (que.empty())
        {
            return -1;
        }
        int size = que.size();
        for (int i = 1; i < size; i++)
        {
            que.push(que.front());
            que.pop();
        }
        int Elem = que.front();
        que.pop();
        return Elem;
    }

    int top()
    {
        if (empty())
            return -1;
        return que.back();
    }

    bool empty()
    {
        return que.empty();
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)
// SYTEM DESIGN
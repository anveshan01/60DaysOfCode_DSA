// 3169 LeetCode
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int freeDays = 0, end = 0;

        sort(meetings.begin(), meetings.end());

        for (auto &meet : meetings)
        {
            int start = meet[0], end = meet[1];

            if (start > end + 1)
            {
                freeDays += start - end - 1;
            }
            end = max(end, end);
        }
        freeDays += days - end;

        return freeDays;
    }
};
// T.C. O(NlogN)
// S.C. O(1)
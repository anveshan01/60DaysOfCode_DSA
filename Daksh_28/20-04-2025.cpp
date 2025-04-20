// 781 LeetCode Greedy
class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        int n = answers.size();
        int answer = 0, cnt = 0;

        if (n == 1)
            return answers[0] + 1;

        sort(answers.begin(), answers.end());

        for (int i = 0; i < n; i++)
        {
            cnt = 0;
            answer += (answers[i] + 1);
            cnt = answers[i];
            while (i < n - 1 and answers[i + 1] == answers[i] and cnt > 0)
            {
                cnt--;
                i++;
            }
        }
        return answer;
    }
};
// T.C O(nlogn)
// S.C O(1)
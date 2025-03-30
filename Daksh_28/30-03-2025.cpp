// 763 LeetCode
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> last;
        vector<int> ans;

        for (int i = 0; i < s.size(); i++)
        {
            last[s[i]] = i;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            end = max(end, last[s[i]]);
            if (i == end)
            {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
// T.C: O(n) S.C: O(1)
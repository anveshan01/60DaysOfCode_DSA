// 2289 LeetCode
// Code Thoda Copy Hai Logic MIK ki video se dekha
class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        vector<int> track(n, 0), vectorSet(n, -1);
        vector<int> result(query.size(), -1);

        for (int i = 0; i < n; i++)
        {
            track[i] = i;
        }
        int diff = 0;
        do
        {
            diff = 0;
            for (int i = 0; i < edges.size(); i++)
            {
                if (track[edges[i][0]] != track[edges[i][1]])
                {
                    track[edges[i][0]] = min((int)track[edges[i][0]], (int)track[edges[i][1]]);
                    track[edges[i][1]] = min((int)track[edges[i][0]], (int)track[edges[i][1]]);
                    diff++;
                }
            }
        } while (diff != 0);

        for (auto &e : edges)
        {
            if (vectorSet[track[e[0]]] == -1)
                vectorSet[track[e[0]]] = e[2];
            vectorSet[track[e[0]]] &= e[2];
        }

        for (int i = 0; i < query.size(); i++)
        {
            if (track[query[i][0]] == track[query[i][1]])
            {
                result[i] = vectorSet[track[query[i][0]]];
            }
        }
        return result;
    }
};
// T.C. O(N + E + Q)
// S.C. O(N + E + Q)
// LeetCode 1128 
class Solution {
    public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            cin.tie(nullptr);
            cout.tie(nullptr);
            int res = 0, s = dominoes.size();
            map<vector<int>, int> mp;
            for (int i = 0; i < s; i++) {
                sort(dominoes[i].begin(), dominoes[i].end());
                mp[dominoes[i]]++;
            }
            for (auto it : mp) {
                int n = it.second;
                res += (n * (n - 1)) / 2;
            }
    
            return res;
        }
    };
// T.C: O(nlogn)
// S.C: O(n)
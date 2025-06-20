// LeetCode 3170
class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> have(26);
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                for (int j = 0; j < 26; ++j) {
                    if (!have[j].empty()) {
                        have[j].pop_back();
                        break;
                    }
                }
            } else {
                have[s[i] - 'a'].push_back(i);
            }
        }
        vector<pair<int, char>> v;
        for (int i = 0; i < 26; ++i) {
            const char c = i + 'a';
            for (int x : have[i]) {
                v.push_back({x, c});
            }
        }
        sort(v.begin(), v.end());
        string r;
        for (const auto& p : v) {
            r.push_back(p.second);
        }
        return r;
    }
};
// T.C: O(n log n)
// S.C: O(n)
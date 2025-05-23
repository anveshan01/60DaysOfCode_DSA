// LeetCode Contest
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int s = 0;
            while (num > 0) {
                s += num % 10;
                num /= 10;
            }
            arr.emplace_back(s, nums[i], i);
        }
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            if (get<0>(a) == get<0>(b))
                return get<1>(a) < get<1>(b);
            return get<0>(a) < get<0>(b);
        });

        vector<int> to_pos(n);
        for (int i = 0; i < n; i++) {
            int orig_index = get<2>(arr[i]);
            to_pos[orig_index] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int cycle_len = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = to_pos[j];
                cycle_len++;
            }

            if (cycle_len > 1) {
                swaps += cycle_len - 1;
            }
        }

        return swaps;
    }
};
//T.C: O(NlogN)
//S.C: O(N)
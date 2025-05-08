// 300 LeetCode 
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<int> sorted;
            for(int i = 0; i < n; i++){
                auto it = lower_bound(begin(sorted),end(sorted), nums[i]);
                if (it == end(sorted)){
                    sorted.push_back(nums[i]);
                }
                else{
                    *it = nums[i];
                }
            }
            return sorted.size();
        }
    };
// T.C : O(nlogn) lower bound 
// S.C : O(n)

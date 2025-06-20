// LeetCode 2294
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] - nums[cnt] > k){
                res++;
                cnt = i;
            }
        }
        return res + 1;
    }
};
// T.C: O(nlogn)
// S.C: O(1)
class Solution {
    long long kelement(vector<int>& nums, int m){
        int left = 0, right = 0;
        int n = nums.size();
        long long count = 0;
        int maxele = 0;
        long long ans = 0;

        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxele = max(maxele, nums[i]);
        }

        while (right < n) {
            if (nums[right] == maxele) {
                count++;
            }

            while (count >m) {
                if (nums[left] == maxele) count--;
                left++;
            }

            ans += (right - left + 1);
            right++;
        }
        return ans;
    }

public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long total=1LL*n*(n+1)/2;
        return total- kelement(nums, k - 1);
    }
};

//https://leetcode.com/problems/max-consecutive-ones-iii/
class Solution {
    public int longestOnes(int[] nums, int k) {
        int l=0,maxL=0,zeros=0;
        for (int r=0; r<nums.length; r++) {
            if (nums[r]==0) zeros++;
            while (zeros>k) {
                if (nums[l] ==0) zeros--;
                l++;
            }
            maxL=Math.max(maxL, r-l+1);
        }
        return maxL;
    }
}
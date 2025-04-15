//https://leetcode.com/problems/3sum-closest/
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int sum =  nums[0]+nums[1]+nums[2];

        for(int i =0; i<nums.length-2;i++){
            int l = i+1;
            int r = nums.length-1;

            while(l<r){
                int curr = nums[i]+nums[l]+nums[r];
                if(curr==target) return curr;
                if(Math.abs(curr-target)<Math.abs(sum-target)){
                    sum=curr;
                }
                if(curr<target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return sum;
    }
}
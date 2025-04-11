class Solution {
    public int f(int[] nums, int idx, int currxor){
        if(idx==nums.length)  return currxor ;
        int take = f(nums,idx+1,currxor^nums[idx]) ;
        int notTake = f(nums,idx+1,currxor) ;
        return take + notTake ;
    }
    public int subsetXORSum(int[] nums) {
        return f(nums,0,0) ;
    }
}
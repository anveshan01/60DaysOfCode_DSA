class Solution {
    public long lowerBound(int[] nums, int low, int high, int target){
        while(low<=high){
            int mid = low + (high-low)/2 ;
            if(nums[mid] >= target){
                high=mid-1 ;
            }
            else{
                low=mid+1 ;
            }
        }
        return low ;
    }
    public long countFairPairs(int[] nums, int lower, int upper) {
        Arrays.sort(nums) ;
        long count = 0 ;
        for(int i=0 ;i<nums.length ;i++){
            long left = lowerBound(nums,i+1,nums.length-1,lower-nums[i]) ;
            long right = lowerBound(nums,i+1,nums.length-1,upper+1-nums[i]) ;
            count += (right-left) ;
        }
        return count ;
    }
}
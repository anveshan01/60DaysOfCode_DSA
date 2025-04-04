class Solution {
    public long maximumTripletValue(int[] nums) {
        long  maxValue = Long.MIN_VALUE ;
        for(int i=0 ;i<nums.length ;i++){
            for(int j=i+1 ;j<nums.length ;j++){
                for(int k=j+1 ;k<nums.length ;k++){
                    long  triplet = ((long)nums[i]-nums[j])*nums[k] ;
                    maxValue = Math.max(maxValue,triplet);
                }
            }
        }
        return maxValue > 0 ? maxValue : 0;
    }
}
class Solution {
    public long maximumTripletValue(int[] nums) {
        int n = nums.length ;
        long maxdiff = 0 ;
        long maxtriplet = 0 ;
        long maxleft = 0 ;

        for(int i=0;i<n; i++){
            maxtriplet = Math.max(maxtriplet,1L*maxdiff*nums[i]) ;//nums[i] used as z
            maxdiff = Math.max(maxdiff,maxleft-nums[i]) ; // nums[i] used as y
            maxleft = Math.max(maxleft,nums[i]);//nums[i] used as x
        }
        return maxtriplet ;
    }
}
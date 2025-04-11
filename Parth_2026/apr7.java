class Solution {

    public boolean f(int[] nums, int idx, int target,Boolean[][] memo){
        if(target==0)   return true ;
        if(idx<0 || target<0)   return false ;
        if(memo[idx][target] != null) return memo[idx][target] ;
        return memo[idx][target] = f(nums,idx-1,target,memo) || f(nums,idx-1,target-nums[idx],memo) ;
    }

    public boolean canPartition(int[] nums) {
        int n = nums.length ;
        int totalSum = 0 ;
        for(int num : nums) totalSum+=num ;
        if(totalSum%2!=0)   return false ;
        int target = totalSum/2 ;
        Boolean [][] memo = new Boolean[n][target+1] ;
        // for(boolean[] row : memo){
        //     Arrays.fill(row,false) ;
        // }
        
        return f(nums,n-1,target,memo) ;
    }
}
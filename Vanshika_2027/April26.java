//https://leetcode.com/problems/jump-game-ii
class Solution {
    public int jump(int[] nums) {
        int j =0, l=0, r=0;
        while(r<nums.length-1){
            int maxI = 0;
            for(int i =l;i<=r;i++){
                maxI = Math.max(maxI, i+nums[i]);
            }
            l=r+1;
            r=maxI;
            j+=1;
        }
        return j;
    }
}
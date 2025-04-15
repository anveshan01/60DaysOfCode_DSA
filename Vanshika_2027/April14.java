//https://leetcode.com/problems/longest-consecutive-sequence/
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int maxLen =1;
        Set<Integer> set = new HashSet<>();
        for(int elem : nums){
            set.add(elem);
        }
        for(int elem : set){
            if(!set.contains(elem-1)){
                int len = 1;
                int val = elem;
                while(set.contains(val+1)){
                    val++;
                    len++;
                }
                maxLen = Math.max(len,maxLen);
            }
        }
        return maxLen;
    }
}
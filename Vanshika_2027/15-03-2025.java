//https://leetcode.com/problems/non-overlapping-intervals/submissions/1574651535/
class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a,b) -> Integer.compare(a[1],b[1]));
        int count =0;
        int lastE = Integer.MIN_VALUE;
        for(int[] interval :intervals){
            if(interval[0]>=lastE){
                lastE = interval[1];
            }else{
                count++;
            }
        }
        return count;
    }
}
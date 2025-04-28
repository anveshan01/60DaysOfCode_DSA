class Solution {
    public int numberOfArrays(int[] differences, int lower, int upper) {
        long min=0 ,max=0 , sum = 0 ;
        for(int ele : differences){
            sum+=ele ;
            min = Math.min(sum,min) ;
            max = Math.max(sum,max) ;
        }

        return (int)Math.max(0L, (upper-max)-(lower-min)+1L) ;
    }
}
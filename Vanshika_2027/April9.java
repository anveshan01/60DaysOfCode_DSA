//https://leetcode.com/problems/koko-eating-bananas/
class Solution {
    static long calHrs(int[] piles, int m){
        long hrs = 0;
        for(int pile:piles){
            hrs+=(pile+m-1L)/m;
        }
        return hrs;
    }
    public int minEatingSpeed(int[] piles, int h) {
        int s=1,e=0;
        for(int pile : piles){
            e= Math.max(e,pile);
        }

        while(s<=e){
            int m = s+(e-s)/2;
            long hrs = calHrs(piles,m);
            if(calHrs(piles,m)<=h){
                e=m-1;
            }else{
                s=m+1;
            }
        }
        return s;
    }
}
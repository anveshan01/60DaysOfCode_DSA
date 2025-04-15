//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
class Solution {
    public boolean bouquet(int[] bloomDay, int m, int k, int mid){
        int count = 0, b = 0;
        for(int bloom : bloomDay){
            if(bloom <= mid){
                count++;
                if(count == k){
                    b++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return b >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        if((long)m * k > bloomDay.length) return -1;
        int s = Integer.MAX_VALUE, e = Integer.MIN_VALUE;
        for(int day : bloomDay){
            s = Math.min(s, day);
            e = Math.max(e, day);
        }
        while(s < e){
            int mid = s + (e - s) / 2;
            if(bouquet(bloomDay, m, k, mid)){
                e = mid;
            } else {
                s = mid + 1;
            }
        }
        return s;
    }
}
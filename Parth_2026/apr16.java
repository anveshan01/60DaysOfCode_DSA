class Solution {
    public long countGood(int[] nums, int k) {
        long n = nums.length ;
        long left = 0 ;
        long right=0 ;
        long good_subarrays = 0 ;
        HashMap<Long,Long> mp = new HashMap<>() ;
        long equal_pairs=0 ;
        while(left<n){
            while(right<n && equal_pairs<k){
                long num = nums[(int)right] ;
                mp.put(num,mp.getOrDefault(num,0L)+1) ;
                if(mp.get(num)>=2){
                    equal_pairs += mp.get(num)-1 ;
                }right++ ;
            }
            if(equal_pairs>=k){
                good_subarrays+=n-right+1 ;
            }

            long leftnum = nums[(int)left] ;
            mp.put(leftnum,mp.get(leftnum)-1) ;
            if(mp.get(leftnum)>0){
                equal_pairs -= mp.get(leftnum) ;
            }
            left++ ;
        }
        return good_subarrays ;
    }
}
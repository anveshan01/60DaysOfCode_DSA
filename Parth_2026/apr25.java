class Solution {
    public long countInterestingSubarrays(List<Integer> nums, int modulo, int k) {
        int n = nums.size() ;
        HashMap<Integer,Integer> mp = new HashMap<>() ;
        long ans = 0 ;
        int prefix = 0 ;
        mp.put(0,1) ;
        for(int i=0 ;i<n ;i++){
            prefix+= nums.get(i)%modulo == k ? 1:0 ;
            ans+= mp.getOrDefault((prefix-k+modulo)%modulo,0) ;
            mp.put(prefix%modulo,mp.getOrDefault(prefix%modulo,0)+1) ;
        }
        
        return ans ;
    }
}
class Solution {
    public int countCompleteSubarrays(int[] nums) {
        Set<Integer> set = new HashSet<>() ;
        for(int num : nums){
            set.add(num) ;
        }
        int n = nums.length ;
        if(set.size()==1)   return (n*(n+1))/2 ;
        int k = set.size() ;
        set.clear() ;
        int count = 0 ;
        for(int i=0 ;i<n ;i++){
            for(int j=i ; j<n ;j++){
                set.add(nums[j]) ;
                if(set.size()==k)   count++ ;
            }
            set.clear() ;
        }
        return count ;
    }
}
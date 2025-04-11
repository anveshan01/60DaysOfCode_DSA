class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> st = new HashSet<>() ;
        for(int num  :nums){
            if(num < k) return -1 ;
            else if(num > k)    st.add(num) ;
        }
        return st.size() ;
    }
}
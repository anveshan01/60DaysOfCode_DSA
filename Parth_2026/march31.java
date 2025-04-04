class Solution {
    public long putMarbles(int[] weights, int k) {
        int n = weights.length ;
        long maxsum = 0 ;
        long minsum = 0 ;
        int[] pairsum = new int[n-1] ;
        Arrays.fill(pairsum,0) ;
        for(int i=0 ;i<n-1 ;i++){
            pairsum[i] = weights[i]+weights[i+1] ;
        }
        Arrays.sort(pairsum) ;
        //k-1 partitions for k bags
        //k-1 pairs 
        for(int i=0 ;i<k-1 ;i++){
            minsum+=pairsum[i] ;
            maxsum+= pairsum[n-1-1-i] ;
        }
        return maxsum - minsum ;
    }
}
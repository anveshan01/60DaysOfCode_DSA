class Solution {
    public long mostPoints(int[][] questions) {
        int n = questions.length ;
        if(n==1)
            return questions[0][0] ;
        long[] dp = new long[2000001] ;//2*10^5
        Arrays.fill(dp,0) ;
        for(int i=n-1 ;i>=0 ;i--){
            dp[i] = Math.max(questions[i][0] + dp[i+questions[i][1]+1], dp[i+1]) ;
        }
        return dp[0] ;
    }
}
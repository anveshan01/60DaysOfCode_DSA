class Solution {
    private static final int MOD = 1000000000 + 7 ;
    private static final int MAX_N = 10010 ;
    private static final int MAX_K = 15 ;

    private long[][] comb = new long[MAX_N][MAX_K] ;

    private void computeCombination(int n){
        for(int i=0 ;i<=n ;i++){
            comb[i][0] = 1 ;
            for(int j=1; j<MAX_K ;j++){
                if(j>i) break ;
                comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%MOD ;
            }
        }
    }

    public int idealArrays(int n, int maxValue) {
        computeCombination(n) ;

        long[][] dp = new long[maxValue+1][MAX_K] ;
        for(int i=1 ;i<=maxValue ; i++){
            dp[i][1] = 1 ;
        }

        for(int k=2 ;k<MAX_K ;k++){
            for(int i=1 ; i<=maxValue ;i++){
                for(int mul = 2*i ; mul<=maxValue ; mul += i){
                    dp[mul][k] = (dp[mul][k] + dp[i][k-1])%MOD ;
                }
            }
        }

        long res = 0 ;
        for(int val = 1 ;val <= maxValue ;val++){
            for(int k = 1 ; k<MAX_K; k++){
                if(k>n) break ;
                res = (res+ dp[val][k]* comb[n-1][k-1])%MOD ;
            }
        }

        return (int)res ;
    }
}
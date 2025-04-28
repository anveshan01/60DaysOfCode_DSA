class Solution {
    static final int MOD = 1_000_000_007 ;
    public long pow(long base, long exp, int mod){
        long res = 1 ;
        base = base %mod ;
        while(exp>0){
            if((exp&1)==1){
                res = (res*base)%mod ;
            }
            base = (base*base)%mod ;
            exp = exp/2 ;
        }
        return res;
    }
    public int countGoodNumbers(long n) {
        if(n==1)    return 5 ;
        long evenIdx = (n+1)/2 ;
        long oddIdx = n/2 ;
        long evenpow = pow(5,evenIdx,MOD) ;
        long oddpow = pow(4,oddIdx,MOD) ;

        return (int)((evenpow*oddpow)%MOD) ;
    }
}
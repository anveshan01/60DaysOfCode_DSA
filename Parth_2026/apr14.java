class Solution {
    public int countGoodTriplets(int[] arr, int a, int b, int c) {
        int cnt=0 ;
        int n = arr.length ;
        int[] sum = new int[1001] ;
        for(int j=0 ;j<n ;j++){
            for(int k=j+1 ;k<n ;k++){
                if(Math.abs(arr[j]-arr[k]) <= b){
                    int lj = arr[j] - a ;
                    int rj = arr[j] + a ;
                    int lk = arr[k] - c ;
                    int rk = arr[k] + c ;
                    int l = Math.max(0,Math.max(lj,lk)) ;
                    int r = Math.min(1000,Math.min(rj,rk)) ;
                    if(l<=r){
                        if(l==0){
                            cnt+= sum[r] ;
                        }
                        else{
                            cnt+=sum[r]-sum[l-1] ;
                        }
                    }
                }
            }
            for(int k=arr[j]; k<1001 ;++k){
                sum[k]++;
            }
        }
        return cnt ;
    }
}
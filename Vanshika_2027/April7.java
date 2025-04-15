// https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?
class Solution {
    static int func(int mid, int n, int m){
        int ans = 1;
        for(int i=1;i<=n;i++){
            ans *= mid;
            if(ans>m) return 2;
        }
        if(ans==m) return 1;
        return 0;
    }
    public int nthRoot(int n, int m) {
        // code here
        int l =1, h=m;
        while(l<=h){
            int mid = l+(h-l)/2;
            int midN = func(mid, n, m);
            if(midN == 1) return mid;
            else if(midN == 2){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return -1;
    }
}
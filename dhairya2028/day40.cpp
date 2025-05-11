int floorSqrt(int n)
{
    // Write your code here.
    int st=0,end=n;
    int ans;
    while(st<=end){
        if(n==1) return 1;
        long long  mid=st+(end-st)/2;
        if(mid*mid>n){
            end=mid-1;
        }
        else if(mid*mid<n){
            ans=mid;
            st=mid+1;
        }
        else return mid;

    }
    return ans;
}

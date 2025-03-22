//GFG PROBLEM
class Solution {
  public:
    bool isvalid(vector <int> &arr,int n,int k,int mid){
        int stu=1,pages=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid) return false;
            if(pages+arr[i]<=mid){
                pages+=arr[i];
            }
            else{
                stu++;
                pages=arr[i];
            }
        }
        return stu>k?false:true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n){
            return -1;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int ans=0;
        int st=0,end=sum;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(isvalid(arr,n,k,mid)){
                end=mid-1;
                ans=mid;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};

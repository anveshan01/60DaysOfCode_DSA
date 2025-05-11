#include <vector>
using namespace std;

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    int st=0,end=n-1;
    
    int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==k) {
            ans= mid;
            end=mid-1;
        }
        else if(arr[mid]<k) st=mid+1;

        else end=mid-1;
    }
    st=0;end=n-1;
    int ans2=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==k) {
            ans2= mid;
            st=mid+1;
        }
        else if(arr[mid]<k) st=mid+1;
        
        else end=mid-1;
    }
    
    return {ans,ans2};
}

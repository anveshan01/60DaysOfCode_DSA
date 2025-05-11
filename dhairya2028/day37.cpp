#include <bits/stdc++.h> 
using namespace std;
void sort012(int *arr, int n)
{
   int mid=0,high=n-1,low=0;
   while(mid<=high){
      if(arr[mid]==0){
         swap(arr[mid],arr[low]);
         low++;
         mid++;
      }
      else if(arr[mid]==1){
         mid++;
      }
      else{
         swap(arr[mid],arr[high]);
         high--;
      }
   }
   

}

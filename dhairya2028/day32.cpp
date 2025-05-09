int findUnique(int *arr, int size)
{
    //Write your code here
    for(int i=0;i<size;i++){
        int x=1;
        for(int j=0;j<size;j++){
            if(arr[i]==arr[j]){
                x++;
            }
        }
        if(x!=2) return arr[i];
    }
}

//optimal approach
int findUnique(int *arr, int size)
{
    //Write your code here
    int ans=0;
    for(int i=0;i<size;i++){
        ans^=arr[i];
    }
    return ans;
}

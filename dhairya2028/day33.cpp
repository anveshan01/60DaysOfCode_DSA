int findDuplicate(vector<int> &arr) 
{
    // Write your code here
    int res=0;
	int n=arr.size();
    for(int i=0;i<n;i++){
        res=res^i;
        res=res^arr[i];
    }
    return res;
}

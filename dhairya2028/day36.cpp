#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;

	for(int i=0;i<n;i++){

		if (i > 0 && arr[i] == arr[i - 1]) continue;
		
		int st=i+1;int end=n-1;
		while (st<end){

			int sum=arr[st]+arr[end];
			if(sum==K-arr[i]){

				vector<int>temp;
				temp.push_back(arr[st]);
				temp.push_back(arr[end]);
				temp.push_back(arr[i]);
				ans.push_back(temp);
				st++;end--;
				 while (st < end && arr[st] == arr[st - 1]) st++;
				 
                while (st < end && arr[end] == arr[end + 1]) end--;
			}
			else if(sum<K-arr[i]){
				st++;
			}
			else {end--;}

		}
		
	}
	return ans;
}

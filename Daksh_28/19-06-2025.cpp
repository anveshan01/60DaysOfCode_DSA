// CodeChef DIVIDE3
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int x = n / 3;
	int remainder = n % 3;
	int min = x;
	int max;
	if(remainder > 0){
	    max = x + 1;
	}
	else{
	    max = x;
	}
	int res = max - min;
	cout << res << endl;
	return 0;

}
// T.C: O(1)
// S.C: O(1)
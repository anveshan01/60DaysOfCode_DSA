// CodeForces Educational Round 177(Rated for Div. 2)
// A
#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << 2 * n << endl;
    }
    return 0;
}

// B
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int countElements(vector<ll> &data, int len, ll target)
{
    int left = 0, right = len;
    while (left < right)
    {
        int middle = left + (right - left) / 2;
        if (data[middle] <= target)
            left = middle + 1;
        else
            right = middle;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;

    while (testCases--)
    {
        int size, copies;
        ll threshold;
        cin >> size >> copies >> threshold;

        vector<int> elements(size);
        for (int idx = 0; idx < size; ++idx)
        {
            cin >> elements[idx];
        }

        vector<ll> prefixSum(size);
        prefixSum[0] = 0;
        for (int idx = 1; idx < size; ++idx)
        {
            prefixSum[idx] = prefixSum[idx - 1] + elements[idx - 1];
        }

        ll totalSum = prefixSum[size - 1] + elements[size - 1];

        if (copies * totalSum < threshold)
        {
            cout << "0\n";
            continue;
        }

        ll diff = copies * totalSum - threshold;
        ll result = 0;

        for (int rep = 0; rep < copies; ++rep)
        {
            ll maxLimit = diff - (ll)rep * totalSum;
            if (maxLimit < 0)
                continue;
            result += countElements(prefixSum, size, maxLimit);
        }
        cout << result << "\n";
    }
    return 0;
}

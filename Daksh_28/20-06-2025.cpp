// CodeChef SUB12
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isFeasible(ll maxVal, int n, const vector<ll>& minReq, const vector<ll>& extra) {
    ll totalShortfall = 0, totalSurplus = 0;

    for (int i = 0; i < n; ++i) {
        if (maxVal < minReq[i]) return false;

        ll take = min(extra[i], maxVal - minReq[i]);
        totalShortfall += extra[i] - take;
    }

    for (int i = 0; i < n; ++i) {
        ll take = min(extra[i], maxVal - minReq[i]);
        ll leftover = maxVal - minReq[i] - take;
        totalSurplus += leftover / 2;
    }

    return totalSurplus >= totalShortfall;
}

ll findMin(int n, const vector<ll>& minReq, const vector<ll>& extra) {
    ll low = *max_element(minReq.begin(), minReq.end());
    ll high = low + accumulate(extra.begin(), extra.end(), 0LL) + 10;

    while (low < high) {
        ll mid = low + (high - low) / 2;
        if (isFeasible(mid, n, minReq, extra)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

void solveTestCase() {
    int n;
    cin >> n;

    vector<ll> minReq(n), extra(n);
    for (ll& val : minReq) cin >> val;
    for (ll& val : extra) cin >> val;

    cout << findMin(n, minReq, extra) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solveTestCase();
    }
}
// T.C: O(n log(max(minReq) + sum(extra)))
// S.C: O(n)
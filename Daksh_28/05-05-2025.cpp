// LeetCode 790 
class Solution {
    public:
    const int mod = 1e9+7;
        int numTilings(int n) {
            array<int,3> a={1,1,2}; // inhi teen basics ke pattern se next banate jao
            if (n < 3) return a[n];
            for(int i = 3; i <= n; i++){
                long long x = (2LL*a[2]+a[0])%mod;
                a={a[1],a[2],(int)x};
            }
        return a[2];
        }
    };
// T.C O(n) 
// S.C O(1)
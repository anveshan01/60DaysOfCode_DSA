// LeetCode 2894 
class Solution {
public:
    int differenceOfSums(int n, int m) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int s1 = 0, s2 = 0;
        for(int i = 1; i <= n; i++){
            if(i % m != 0){
                s1 += i;
            }
            if(i % m == 0){
                s2 += i;
            }
        }
        return s1 - s2;
    }
};
// T.C: O(N)
// S.C: O(1)

// LeetCode 2928
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
    for(int i = 0; i <= limit; ++i){
        for(int j = 0; j <= limit; ++j){
            for(int k = 0; k <= limit; ++k){
                if(i + j + k == n) { res++; }
            }
        }
    }
    return res;
}
};
// T.C: O(n^3)
// S.C: O(1)
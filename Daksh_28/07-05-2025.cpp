// 70 LeetCode 
// DP practice
class Solution {
    public:
    int t[46];
        int solve(int n) {
            if(n < 0){
                return 0;
            }
            if(t[n] != -1){
                return t[n];
            }
            if(n == 0){
                return 1;
            }
            int one = solve(n-1);
            int two = solve(n-2);
    
            return t[n] = one + two;
        }
        int climbStairs(int n){
            memset(t, -1, sizeof(t));
            return solve(n);
        }
    };
// T.C O(n)
// S.C O(n)
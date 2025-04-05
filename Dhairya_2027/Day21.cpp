//1-04-2025

long long dp[100000];
class Solution {
public:
    long long dfs(vector<vector<int>>& q, int i){
        if (i>=q.size()) return 0;
        if (dp[i]!=-1) return dp[i];
        long long pt=q[i][0];
        int skip=q[i][1];
        dp[i]=max(pt+dfs(q, i+skip+1), dfs(q, i+1));
        return dp[i];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        const int n=questions.size();
        memset(dp, -1, n*sizeof(long long));
        return dfs(questions, 0);       
    }
};

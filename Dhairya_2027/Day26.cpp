//6-04-2025

//POTD 6 Leetcode

class Solution {
    public:
        int dp[1010][1010];
        vector<int> v;
        vector<int> ans;
        int n;
    
        int rec(int level, int lst_taken){
            if(level >= n) return 0;
    
            if(dp[level][lst_taken+1] != -1) return dp[level][lst_taken+1];
    
            int ans = rec(level+1, lst_taken);  // dont take.
            if(lst_taken != -1){
                if(v[level]%v[lst_taken] == 0){
                    ans = max(ans, rec(level+1, level)+1);
                }
            }
            else{
                ans = max(ans, rec(level+1, level)+1);
            }
    
            return dp[level][lst_taken+1] = ans;
        }
    
        void generate(int level, int lst_taken){
            if(level >= n) return;
            int donttake = rec(level+1, lst_taken);
    
            int take=-1;
            if(lst_taken == -1){
                take = rec(level+1, level)+1;
            }
            else{
                if(v[level]%v[lst_taken] == 0){
                    take = rec(level+1, level)+1;
                }
            }
    
            if(take >= donttake){
                ans.push_back(v[level]);
                generate(level+1, level);
            }
            else generate(level+1, lst_taken);
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            n = nums.size();
            sort(nums.begin(), nums.end());
            memset(dp, -1, sizeof(dp));
            for(auto it : nums){
                v.push_back(it);
            }
    
            rec(0,-1); 
            generate(0,-1);
            return ans;
        }
    };
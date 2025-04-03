class Solution {
    public:
    //brute force not allowed in this
        long long maximumTripletValue(vector<int>& nums) {
          int n=nums.size();
          long long largest=0;
          long long largestdiff=0;
          long long ans=0;
          for(int i=0;i<n;i++){
            ans=max(ans,nums[i]*largestdiff);
            largest=max(largest,(long long)nums[i]);
            largestdiff=max(largestdiff,(long long)(largest-nums[i]));
          }
          return ans;
        }
    };
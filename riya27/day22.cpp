class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n=nums.size();
            long long ans=0;
           // long long MOD=1e9+7;
            for(long long i=0;i<n;i++){
                for(long long j=i+1;j<n;j++){
                    for(long long k=j+1;k<n;k++){
                        long long pro=((long long)(nums[i]-nums[j])*(long long)nums[k]);
    
                            ans=max(ans,pro);
                        
                    }
                }
            }
            return ans;
        }
    };
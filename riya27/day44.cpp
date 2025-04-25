lass Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            long long ans=0;
            int prefix=0;
            unordered_map<int,int>mpp;
            mpp[0]=1;
            for(int num:nums){
                if(num%modulo==k){
                    prefix++;
                }
                int mod=prefix % modulo;
                int target=(mod-k+modulo)%modulo;
                ans+=mpp[target];
                mpp[mod]++;
            }  
            return ans;      
        }
    };
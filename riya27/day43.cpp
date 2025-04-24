class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
            int ans=0;
            int n=nums.size();
            unordered_set<int>distinct(nums.begin(),nums.end());
            int k=distinct.size();
            for(int i=0;i<n;i++){
                unordered_map<int,int>mpp;
                for(int j=i;j<n;j++){
                    mpp[nums[j]]++;
                    if(mpp.size()==k){
                        ans++;
                    }
                    else if(mpp.size()>k){
                        break;
                    }
                }
            }
           return ans;
            
        }
    };
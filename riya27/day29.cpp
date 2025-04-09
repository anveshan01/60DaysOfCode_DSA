class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int count=0;
            int n=nums.size();
            sort(nums.begin(),nums.end());
            unordered_map<int,int>mpp;
            for(int i=0;i<n;i++){
                mpp[nums[i]]++;
            }
            for(auto it:mpp){
                if(it.first<k){
                    return -1;
                }else if(it.first>k){
                    count++;
                }
            }
            //if(n>1 && count==0) return -1;
            return count;
            
        }
    };
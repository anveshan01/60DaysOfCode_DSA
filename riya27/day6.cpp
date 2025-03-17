class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            sort(nums.begin(),nums.end());
            int n=nums.size();
            if(n%2!=0) return false;
            map<int,int>mpp;
            for(int i=0;i<n;i++){
               mpp[nums[i]]++;
            }
            for(auto it:mpp){
                if(it.second%2!=0){
                    return false;
                }
            }
          return true;  
        }
    };
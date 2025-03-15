//solved using binary search and greedy approach
class Solution {
    public:
        int minCapability(vector<int>& nums, int k) {
            int minamount=1;
            int maxamount=*max_element(nums.begin(),nums.end());
            int n=nums.size();
            int left=0;
            int right=n;
            while(minamount<maxamount){
                int midamount=(minamount+maxamount)/2;
                int posrob=0;
                for(int i=0;i<n;i++){
                    if(nums[i]<=midamount){
                        posrob++;
                        i++;
                    }
                }
                if(posrob>=k){
                    maxamount=midamount;
                }
                else{
                    minamount=midamount+1;
                }
            }
            return minamount;
            
        }
    };
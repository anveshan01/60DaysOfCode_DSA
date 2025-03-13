#kadane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=INT_MIN;
        int currsum=0;
        for(int st=0;st<n;st++){
            
            currsum+=nums[st];
            maxsum=max(maxsum,currsum);
            if(currsum<0){
                currsum=0;
            }
            
        }
        return maxsum;
    }
};

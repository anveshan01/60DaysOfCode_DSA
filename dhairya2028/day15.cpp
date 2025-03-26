//75. Sort Colors problem
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int countZero=0;
        int countOne=0 ;
        int countTwo=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) countZero++;
            else if(nums[i]==1) countOne++;
            else countTwo++;
        }
        for(int i=0;i<n;i++){
            if(countZero>0){
                nums[i]=0;
                countZero--;
            }
            else if(countOne>0){
                nums[i]=1;
                countOne--;
            }
            else nums[i]=2;

        }
    }
};

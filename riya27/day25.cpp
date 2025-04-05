class Solution {
    void subset(int index, int sum,vector<int>& nums, vector<int>&total){
        if(index>=nums.size()){
            total.push_back(sum);
            return;
        }
        subset(index+1,sum,nums,total);
        
        subset(index+1,sum^nums[index],nums,total);
        //return total;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        vector<int>output;
        int index=0;
        vector<int>total;
        subset(index,sum,nums,total);
        int res=0;
        for(int i=0;i<total.size();i++){
           res+=total[i];
        }
        return res;
    }
};
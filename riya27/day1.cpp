//max count of positive or negative numbers in an array
//Time Complexity: O(n)
int maximumCount(vector<int>& nums) {
    int negcount=0;
    int poscount=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>0){
            poscount++;
        }
        if(nums[i]<0){
            negcount++;
        }
    }
    return max(poscount,negcount);
}
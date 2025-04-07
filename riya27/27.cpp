lass Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int total=0;
            for(int i=0;i<nums.size();i++){
                total+=nums[i];
            }
            if(total%2!=0) return false;
            bitset<10001>bit(1);
            for(auto i:nums){
                bit|=bit<<i;
                if(bit[total/2]){
                    return true;
                }
            }
            return bit[total/2];
        }
    };
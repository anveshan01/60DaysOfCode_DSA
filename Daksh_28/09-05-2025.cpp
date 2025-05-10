// 2765 
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0,m=1;
        for(int i = 0;i<n;i++){
            int cnt = 1;
            bool f = 0;
            for(int j= i;j<n-1;j++){
                if(f==0) {
                    if(nums[j+1] - nums[j]==1) {
                        cnt+=1;
                        f = 1;
                    }
                    else break;
                    
                }
                else{
                    if(nums[j]-nums[j+1]==1) {
                        cnt+=1;
                        f = 0;
                    }else break;
                }
            }
            m = max(m , cnt);
        }
       if(m!=1) return m;
        else return -1;
    }
};
// T.C : O(n^2)
// S.C : O(1)
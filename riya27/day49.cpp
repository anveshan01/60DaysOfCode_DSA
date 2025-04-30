class Solution {
    int countdigit(int n){
       int count=0;
       while(n>0){
        n=n/10;
        count++;
       }
       return count;
    }
public:
    int findNumbers(vector<int>& nums) {
         int ans=0;
         for(int i=0;i<nums.size();i++){
               int digit=countdigit(nums[i]);
               if(digit%2==0){
                   ans++;  
               }
         }
         return ans;
    }
};
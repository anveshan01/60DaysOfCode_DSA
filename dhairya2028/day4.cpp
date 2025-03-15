#Majority_element(opti-bute_approach)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int freq=1,ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                freq++;
            }
            else{
                freq=1;
                ans=nums[i];

            }
            if(freq>n/2){
                return ans;
            }
            
        }
        return ans;
    }
};


//(Most_optimum_approach moore's algorithm)
  class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int freq=0,ans=nums[0];
        for(int i=0;i<n;i++){
            if(freq==0) ans=nums[i];
            if(nums[i]==ans){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans;

    }

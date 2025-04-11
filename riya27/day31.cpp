class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count=0;
           for(int i=low;i<=high;i++){
              string nums=to_string(i);
              long long n=nums.size();
              long long sum=0;
              for(int j=0;j<n/2;j++){
                   sum+=nums[j];
              }
              for(int k=n/2;k<n;k++){
                sum-=nums[k];
              }
              if(sum==0){
                count++;
              }
          }
          return count;
            
        }
    };
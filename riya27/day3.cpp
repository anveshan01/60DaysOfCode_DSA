class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
         int maxcandy=0;
         for(int i=0;i<candies.size();i++){
            maxcandy=max(maxcandy,candies[i]);
         }
         int left=0;
         int right=maxcandy;
         while(left<right){
            int middle=(left+right+1)/2;
            if(canallocatecandy(candies,k,middle)){
                left=middle;
            }else{
                right=middle-1;
            }
         }
         return left;
            
        }
        bool canallocatecandy(vector<int>& candies, long long k,int num){
            long long int maxchildren=0;
            for(int i=0;i<candies.size();i++){
                maxchildren+=candies[i]/num;
            }
            return maxchildren>=k;
        }
    };
class Solution {
    public:
        bool canAllocate(vector<int>& candies, long long k, int mid){
            long long int children=0 ;
            for(int i=0 ;i<candies.size(); i++){
                children+=candies[i]/mid ;
            }
            return children >= k ;
        }
    
        int maximumCandies(vector<int>& candies, long long k) {
            int maxcandies = 0 ;
            for(int i=0 ;i<candies.size() ;i++){
                maxcandies = max(maxcandies,candies[i]) ;
            }
            int low = 0 ;
            int high = maxcandies ;
            while(low<high){
                int mid = (low + high +1)/2 ;
                if(canAllocate(candies,k,mid)){
                    low = mid ;
                }
                else{
                    high=mid-1 ;
                }
            }
            return low ;
        }
    };
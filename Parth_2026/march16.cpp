class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            int minrank = *min_element(begin(ranks),end(ranks)) ;
            int maxrank = *max_element(begin(ranks),end(ranks)) ;
    
            vector<int> vec(maxrank+1) ;
            for(int rank : ranks)
                vec[rank]++ ;
            long long low = 1; 
            long long high = 1LL*minrank*cars*cars ;
            while(low<high){
                long long mid = low + (high-low)/2 ;
                long long repaired = 0 ;
                for(int rank=1 ; rank<=maxrank ;rank++){
                    repaired+= vec[rank]*(long long)sqrt(mid/(long long)rank) ;
                }
                if(repaired>=cars){
                    high=mid ;
                }
                else{
                    low = mid+1 ;
                }
            }
            return low ;
        }
    };
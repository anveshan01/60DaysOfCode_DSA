class Solution {
    public:
        long long repairCars(vector<int>& ranks, int cars) {
            int n=ranks.size();
            int minrank=ranks[0];
            int maxrank=ranks[0];
            for(auto it:ranks){
                minrank=min(minrank,it);
                maxrank=max(it,maxrank);
            }
            vector<int>freq(maxrank+1);
            for(int i=0;i<ranks.size();i++){
                freq[ranks[i]]++;
            }
            long long low=0;
            long long high=1LL * minrank*cars* cars;
            while(low<high){
                long long mid=(low+high)/2;
                long long maxcar=0;
                for(int i=1;i<=maxrank;i++){
                    maxcar+=freq[i]*(long long) sqrt(mid/(long long)i);
                }
                if(maxcar>=cars){
                    high=mid;
                }else{
                    low=mid+1;
                }
            }
            return low;
        }
    };
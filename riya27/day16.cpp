class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            map<int,int>mpp;
            int n=nums.size();
            for(int i=0;i<n;i++){
                mpp[nums[i]]++;
            }
            int count=0;
            int ele=0;
            for(auto it:mpp){
               int maxi=it.second;
               if(maxi>count){
                count=maxi;
                ele=it.first;
               }
            }
            if(count<=n/2) return -1;
            int ind=-1;
            int elecount=0;
            for(int i=0;i<n;i++){
                if(nums[i]==ele){
                    elecount++;
                }
                if((elecount*2)>(i+1) && (count-elecount)*2>(n-i-1) ){
                    ind=i;
                    break;
                    
                }
            }
            return ind;
            
        }
    };
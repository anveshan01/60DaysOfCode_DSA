class Solution {
    public:
        //bs to find first zero value.
        int firstZero(vector<int>& nums){
            int start=0,end=nums.size()-1 ;
            int idx = nums.size() ;
    
            while(start<=end){
                int mid = start + (end-start)/2 ;
                if(nums[mid]<0){
                    start=mid+1 ;
                }
                else if (nums[mid]>=0){
                    end=mid-1 ;
                    idx = mid ;
                }
            }
        return idx ;
        }
    
        //bs to find first positive value.
        int firstPos(vector<int>& nums){
            int start=0,end=nums.size()-1 ;
            int idx = nums.size() ;
    
            while(start<=end){
                int mid = start + (end-start)/2 ;
                if(nums[mid]<=0){
                    start=mid+1 ;
                }
                else if (nums[mid]>0){
                    end=mid-1 ;
                    idx = mid ;
                }
            }
        return idx ;
        }
    
        int maximumCount(vector<int>& nums) {
            int pos = nums.size() - firstPos(nums) ;
            int neg = firstZero(nums) ;
            return max(pos,neg) ;
        }
    };
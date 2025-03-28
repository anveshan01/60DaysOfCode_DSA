class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
            int n = nums.size() ;
            unordered_map<int,int> mp1 ;
            for(auto num : nums){
                mp1[num]++ ;
            }
            unordered_map<int,int> mp2 ;
            for(int i=0 ;i<n ;i++){
                int ele = nums[i] ;
                mp1[ele]-- ;
                mp2[ele]++ ;
                if(mp2[ele]*2 > i+1 && mp1[ele]*2 > n-i-1 ) {
                    return i ;
                }
            }
            return -1 ;
        }
    };
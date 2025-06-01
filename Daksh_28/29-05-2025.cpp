// LeetCode 16
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end()); 

        int current_sum = 0;
        int min_diff = INT_MAX;

        for (int i = 0 ; i < nums.size() ; i++){

            int start = i + 1 , end  = nums.size() - 1   ; 

            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                int diff = abs(sum - target) ;
                if (diff < min_diff){
                    min_diff = diff ; 
                    current_sum = sum ;
                }
                if (sum == target){
                    return sum;
                }
                else if (sum < target){
                    start ++ ;

                }
                else {

                    end --;

                }
            }

        }

        return current_sum ; 
    }
};
// T.C: O(n^2)
// S.C: O(1)
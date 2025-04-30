// 1295 LeetCode 
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int c=0;
            for (int i=0;i<nums.size();i++){
                int n=0;
                int x=nums[i];
                while(x!=0){
                    n++;
                    x=x/10;
                }
                if (n%2==0){
                    c++;
                }
            }
            return c;
        }
    };
// T.C: O(n)
// S.C: O(1)

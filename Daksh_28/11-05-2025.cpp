// 1550 LeetCode 
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt;
        for(int i : arr){
            if(i % 2 != 0){
                cnt++;
                if(cnt == 3){
                    return true;
                }
            }
            else{
                cnt = 0;
            }

        }
        return false;
    }
};
// T.C : O(n)
// S.C : O(1)
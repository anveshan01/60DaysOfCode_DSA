// LeetCode 1431

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans;
        int ma = *max_element(begin(candies), end(candies));

        for(int i = 0; i < n ; i++){
            if(candies[i] + extraCandies >= ma){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};

//T.C: O(N)
//S.C: O(N)

class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            vector<int>Ans;
            int n=cost.size();
            int mini=cost[0];
            for(int i=1;i<n;i++){
                Ans.push_back(mini);
                mini=min(mini,cost[i]);
                
            }
            Ans.push_back(mini);
            return Ans;
        }
    };
class Solution {
    bool check(vector<vector<int>>&interval){
        sort(interval.begin(),interval.end());
        int max_end=interval[0][1];
        int section=0;
        for(auto& inter:interval){
            int start=inter[0], end=inter[1];
            if(max_end<=start){
                section++;
            }
            max_end=max(max_end,end);
        }
        return section>=2;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>xinterval,yinterval;
        for(auto&rec:rectangles){
            xinterval.push_back({rec[0],rec[2]});
            yinterval.push_back({rec[1],rec[3]});
        }
        return check(xinterval)|| check(yinterval);
        
    }
};
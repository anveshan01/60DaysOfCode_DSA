class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
        
           sort(meetings.begin(),meetings.end());
            vector<vector<int>>merged;
            merged.push_back(meetings[0]);
           for(int i=1;i<meetings.size();i++){
            vector<int>&last=merged.back();
            if(last[1]>=meetings[i][0]){
              last[1]=max(last[1],meetings[i][1]);
           }else{
             merged.push_back(meetings[i]);
           }
           }
           int n=merged.size();
           
           int count=0;
            count += (merged[0][0] - 1);  // Days before first meeting
           for(int i=1;i<merged.size();i++){
             count+=(merged[i][0]-merged[i-1][1]-1);
            
          
    
           }
           count += (days - merged.back()[1]);  // Days after last meeting
           return count;
            
        }
    };
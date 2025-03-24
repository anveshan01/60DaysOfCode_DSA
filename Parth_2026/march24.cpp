class Solution {
    public:
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(begin(meetings),end(meetings),[](const vector<int>&a,const vector<int>&b){
                return a[0] < b[0] ;
            });
    
            int countOfDays = 0 ;
            int lastBusy = 0 ;
            for(auto& meeting : meetings){
                int start = meeting[0] ;
                int end = meeting[1] ;
                if(start > lastBusy+1){
                    countOfDays += (start-lastBusy-1) ;
                }
                lastBusy = max(lastBusy,end) ;
            }
            if(lastBusy < days)
                countOfDays+=(days-lastBusy) ;
            return countOfDays ;
        }
    };